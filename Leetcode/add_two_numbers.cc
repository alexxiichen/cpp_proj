/*
    题目：两数相加
    给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序
    的方式存储的，并且它们的每个节点只能存储 一位 数字。
    如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
    您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
    示例：
        输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
        输出：7 -> 0 -> 8
        原因：342 + 465 = 807
*/
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
    // fuck 这里理解错了题意，是倒序的
    // 正序的，但是会溢出
    static ListNode* addTwoNumbers_positive(ListNode* l1, ListNode* l2) {
        unsigned int value1 = 0;
        unsigned int value2 = 0;
        unsigned int sum = 0;
        do {
            value1 = value1 * 10 + l1->val;
        } while ((l1 = l1->next) != nullptr);
        std::cout << value1 << std::endl;

        do {
            value2 = value2 * 10 + l2->val;
        } while ((l2 = l2->next) != nullptr);
        std::cout << value2 << std::endl;

        sum = value1 + value2;
        std::cout << sum << std::endl;
        ListNode* headSumlist = nullptr;
        ListNode* sumlist = nullptr;
        char str[256];
        sprintf(str, "%u", sum);
        std::cout << str << std::endl;

        for (int i = 0; str[i] != '\0'; i++) {
            if (i == 0) {
                headSumlist = sumlist = new ListNode(str[i] - '0');
            } else {
                sumlist->next = new ListNode(str[i] - '0');
                sumlist = sumlist->next;
            }
        }
        return headSumlist;
    }

    // 倒序的，但是会溢出
    static ListNode* addTwoNumbers_revers(ListNode* l1, ListNode* l2) {
        unsigned int value1 = l1->val;
        unsigned int value2 = l2->val;
        unsigned int sum = 0;

        for (int i = 1; (l1 = l1->next) != nullptr; i++) {
            value1 = value1 + l1->val * std::pow(10, i);
        }
        // std::cout << value1 << std::endl;

        for (int i = 1; (l2 = l2->next) != nullptr; i++) {
            value2 = value2 + l2->val * std::pow(10, i);
        }
        // std::cout << value2 << std::endl;

        sum = value1 + value2;
        // std::cout << sum << std::endl;

        ListNode* headSumlist = nullptr;
        ListNode* sumlist = nullptr;
        char str[256];
        int i = 0;

        for (i = 0; sum > 0; i++) {
            str[i] = sum % 10 + '0';
            sum = sum / 10;
        }
        str[i] = '\0';
        // std::cout << str << std::endl;

        for (int i = 0; str[i] != '\0'; i++) {
            if (i == 0) {
                headSumlist = sumlist = new ListNode(str[i] - '0');
            } else {
                sumlist->next = new ListNode(str[i] - '0');
                sumlist = sumlist->next;
            }
        }
        return headSumlist;
    }

    //正确答案，不会溢出
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* curr = dummyHead;
        int carry = 0;
        while (p != nullptr || q != nullptr) {
            int x = (p != nullptr) ? p->val : 0;
            int y = (q != nullptr) ? q->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (p != nullptr) p = p->next;
            if (q != nullptr) q = q->next;
        }
        if (carry > 0) {
            curr->next = new ListNode(carry);
        }
        return dummyHead->next;
    }
};

void trimLeftTrailingSpaces(string& input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(),
                                       [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string& input) {
    input.erase(find_if(input.rbegin(), input.rend(),
                        [](int ch) { return !isspace(ch); })
                    .base(),
                input.end());
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

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for (int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);

        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}