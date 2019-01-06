/*
    题目：两数之和
    给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那
    两个整数，并返回他们的数组下标。
    你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
    示例:
        给定 nums = [2, 7, 11, 15], target = 9
        因为 nums[0] + nums[1] = 2 + 7 = 9
        所以返回 [0, 1]
 */

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

template <class T>
static void print(vector<T> vec) {
    cout << "[";
    for (int i = 0; i < vec.size() - 1; i++) {
        cout << vec[i] << ",";
    }
    cout << vec[vec.size() - 1] << "]" << endl;
}

class Solution {
  public:
    // 暴力法
    // 时间复杂度O(n)
    // 空间复杂度O(1)
    static vector<int> twoSum_V1(vector<int>& nums, int target) {
        vector<int> result;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    int result[] = {i, j};
                    return vector<int>(result, result + 2);
                }
            }
        }
        return vector<int>(1, -1);
    }

    // 两次hash法
    // 时间复杂度O(n)
    // 最好情况应该是O(1)如果有冲突就是O(n)
    // 空间复杂度O(1)
    static vector<int> twoSum_V2(vector<int>& nums, int target) {
        unordered_map<int, int> unord_map;
        for (int i = 0; i < nums.size(); i++) {
            unord_map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (unord_map.find(complement) != unord_map.end() && i != unord_map[complement]) {
                int result[] = {i, unord_map[complement]};
                return vector<int>(result, result + 2);
            }
        }
        return vector<int>(1, -1);
    }

    // 一次hash法
    // 时间复杂度O(n)
    // 最好情况应该是O(1)如果有冲突就是O(n)
    // 空间复杂度O(1)
    static vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> unord_map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (unord_map.find(complement) != unord_map.end()) {
                int result[] = {i, unord_map[complement]};
                return vector<int>(result, result + 2);
            }
            unord_map[nums[i]] = i;
        }
        return vector<int>(1, -1);
    }
};

void trimLeftTrailingSpaces(string& input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string& input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) { return stoi(input); }

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for (int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        vector<int> ret = Solution().twoSum(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}