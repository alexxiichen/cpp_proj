/*
    题目：寻找两个有序数组的中位数
    给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
    请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
    你可以假设 nums1 和 nums2 不会同时为空。
    示例 1:
        nums1 = [1, 3]
        nums2 = [2]
        则中位数是 2.0
    示例 2:
        nums1 = [1, 2]
        nums2 = [3, 4]
        则中位数是 (2 + 3)/2 = 2.5
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>::iterator it1 = nums1.begin();
        vector<int>::iterator it2 = nums2.begin();
        vector<int> result;
        // result.resize(nums1.size() + nums2.size());
        do {
            if (it1 == nums1.end()) {
                result.push_back(*(it2++));
            } else if (it2 == nums2.end()) {
                result.push_back(*(it1++));
            } else if (*it1 < *it2) {
                result.push_back(*(it1++));
            } else if (*it1 == *it2) {
                result.push_back(*(it1++));
                result.push_back(*(it2++));
            } else {
                result.push_back(*(it2++));
            }
        } while (it1 != nums1.end() || it2 != nums2.end());
        if (result.size() % 2 != 0) {
            return result[result.size() / 2];
        } else {
            return (result[result.size() / 2 - 1] + result[result.size() / 2]) / 2.0;
        }
        return 0;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);

        double ret = Solution().findMedianSortedArrays(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}