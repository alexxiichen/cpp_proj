
#include <string.h>
#include <sys/time.h>
#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
#include <vector>

// 从文件中读取ID值，保存到map中
int ReadDataFile(const std::string &file_name, std::map<int, int> &map_result) {
    FILE *fp = fopen(file_name.c_str(), "r");
    if (fp == NULL) {
        perror("Open file fail");
        return -1;
    }
    map_result.clear();
    char buf[100];
    int id;
    while (true) {
        memset(buf, 0, sizeof(buf));
        if (fgets(buf, sizeof(buf), fp) == NULL) {
            break;
        }
        id = atoi(buf);
        ++map_result[id];  // 记录ID出现次数
    }
    fclose(fp);
    return 0;
}

// 最终结果
typedef struct Result {
    int id;     // ID值
    int times;  // 该ID值出现的次数

    Result() {
        id = 0;
        times = 0;
    }
    // 根据ID出现次数比较大小
    bool operator>(const Result &other) const { return times > other.times; }
} Result;

// 从map中获取top k的值，并保存到存储Result对象的vector容器中
void GetTopK(std::map<int, int> &map_result, std::vector<Result> *final_result, int k) {
    // k值可能比map_result中的元素个数要多
    size_t min_k = std::min((int)map_result.size(), k);
    std::vector<Result> heap;
    heap.resize(min_k);
    // 创建一个小顶堆，即出现次数最少的ID在堆顶位置
    // make_heap默认创建的是大顶堆，第三个参数是less
    std::make_heap(heap.begin(), heap.end(), std::greater<Result>());

    Result tmp;
    for (auto &it : map_result) {
        tmp.times = it.second;
        // 只需要处理ID出现次数大于堆顶位置元素的情况
        if (tmp.times < heap[0].times) {
            continue;
        }
        tmp.id = it.first;
        heap[0] = tmp;
        std::make_heap(heap.begin(), heap.end(), std::greater<Result>());
    }
    std::sort_heap(heap.begin(), heap.end(), std::greater<Result>());
    final_result->clear();
    final_result->swap(heap);
}

// 直接排序
void DirectSort(std::map<int, int> &map_result, std::vector<Result> *final_result, int k) {
    std::vector<Result> result;
    Result tmp;
    for (auto &it : map_result) {
        tmp.id = it.first;
        tmp.times = it.second;
        result.push_back(tmp);
    }
    std::sort(result.begin(), result.end(), std::greater<Result>());
    final_result->clear();
    final_result->swap(result);
    // k值可能比map_result中的元素个数要多
    size_t min_k = std::min((int)map_result.size(), k);
    final_result->resize(min_k);
}

// 获取微秒时间
long GetUsTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
}

int main(int argc, char **argv) {
    // 读取文件数据并保存到map
    const std::string file_name = "test.data";
    std::map<int, int> map_result;
    int ret = ReadDataFile(file_name, map_result);
    if (ret < 0) {
        printf("ERROR: ReadDataFile fail\n");
        return -1;
    }
    printf("map_result size:%lu\n", map_result.size());

    // 获取出现次数最多的10个ID值
    std::vector<Result> final_result;
    long start = GetUsTime();
    GetTopK(map_result, &final_result, 10);
    long end = GetUsTime();
    printf("GetTopK used time: %ldms\n", (end - start) / 1000);
    for (auto &it : final_result) {
        printf("id: %6d, times: %d\n", it.id, it.times);
    }

    // 直接排序
    final_result.clear();
    start = GetUsTime();
    DirectSort(map_result, &final_result, 10);
    end = GetUsTime();
    printf("DirectSort used time: %ldms\n", (end - start) / 1000);
    for (auto &it : final_result) {
        printf("id: %6d, times: %d\n", it.id, it.times);
    }
    return 0;
}