#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

template <class T> static void print(vector<T> vec)
{
    cout << "[";
    for (int i = 0; i < vec.size() - 1; i++)
    {
        cout << vec[i] << ",";
    }
    cout << vec[vec.size() - 1] << "]" << endl;
}

class Solution
{
  public:
    // 暴力法
    // 时间复杂度O(n)
    // 空间复杂度O(1)
    static vector<int> twoSum_V1(vector<int>& nums, int target)
    {
        vector<int> result;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
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
    static vector<int> twoSum_V2(vector<int>& nums, int target)
    {
        unordered_map<int, int> unord_map;
        for (int i = 0; i < nums.size(); i++)
        {
            unord_map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (unord_map.find(complement) != unord_map.end() &&
                i != unord_map[complement])
            {
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
    static vector<int> twoSum_V3(vector<int>& nums, int target)
    {
        unordered_map<int, int> unord_map;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (unord_map.find(complement) != unord_map.end())
            {
                int result[] = {i, unord_map[complement]};
                return vector<int>(result, result + 2);
            }
            unord_map[nums[i]] = i;
        }
        return vector<int>(1, -1);
    }
};

int main(int argc, char const* argv[])
{
    vector<int> testVec;
    testVec.push_back(2);
    testVec.push_back(7);
    testVec.push_back(11);
    testVec.push_back(15);
    print(Solution::twoSum_V1(testVec, 9));
    print(Solution::twoSum_V2(testVec, 9));
    print(Solution::twoSum_V3(testVec, 9));
    return 0;
}