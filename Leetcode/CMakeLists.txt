CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(Leetcode VERSION 0.1.0)

INCLUDE(CTest)
ENABLE_TESTING()

#leetcode:1 两数之和
ADD_EXECUTABLE(two_sum two_sum.cc)

#leetcode:2 两数相加
ADD_EXECUTABLE(add_two_numbers add_two_numbers.cc)

#leetcode:3 无重复字符的最长字串
ADD_EXECUTABLE(longest_substring_without_repeating_characters longest_substring_without_repeating_characters.cc)

#leetcode:4 寻找两个有序数组的中位数
ADD_EXECUTABLE(median-of-two-sorted-arrays median-of-two-sorted-arrays.cc)