#include <cmath>
#include <iostream>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
  public:
    // fuck 这里理解错了题意，是倒序的
    // 正序的，但是会溢出
    static ListNode* addTwoNumbers_positive(ListNode* l1, ListNode* l2)
    {
        unsigned int value1 = 0;
        unsigned int value2 = 0;
        unsigned int sum = 0;
        do
            {
                value1 = value1 * 10 + l1->val;
            }
        while ((l1 = l1->next) != nullptr);
        std::cout << value1 << std::endl;

        do
            {
                value2 = value2 * 10 + l2->val;
            }
        while ((l2 = l2->next) != nullptr);
        std::cout << value2 << std::endl;

        sum = value1 + value2;
        std::cout << sum << std::endl;
        ListNode* headSumlist = nullptr;
        ListNode* sumlist = nullptr;
        char str[256];
        sprintf(str, "%u", sum);
        std::cout << str << std::endl;

        for (int i = 0; str[i] != '\0'; i++)
            {
                if (i == 0)
                    {
                        headSumlist = sumlist = new ListNode(str[i] - '0');
                    }
                else
                    {
                        sumlist->next = new ListNode(str[i] - '0');
                        sumlist = sumlist->next;
                    }
            }
        return headSumlist;
    }

    // 倒序的，但是会溢出
    static ListNode* addTwoNumbers_revers(ListNode* l1, ListNode* l2)
    {
        unsigned int value1 = l1->val;
        unsigned int value2 = l2->val;
        unsigned int sum = 0;

        for (int i = 1; (l1 = l1->next) != nullptr; i++)
            {
                value1 = value1 + l1->val * std::pow(10, i);
            }
        // std::cout << value1 << std::endl;

        for (int i = 1; (l2 = l2->next) != nullptr; i++)
            {
                value2 = value2 + l2->val * std::pow(10, i);
            }
        // std::cout << value2 << std::endl;

        sum = value1 + value2;
        // std::cout << sum << std::endl;

        ListNode* headSumlist = nullptr;
        ListNode* sumlist = nullptr;
        char str[256];
        int i = 0;

        for (i = 0; sum > 0; i++)
            {
                str[i] = sum % 10 + '0';
                sum = sum / 10;
            }
        str[i] = '\0';
        // std::cout << str << std::endl;

        for (int i = 0; str[i] != '\0'; i++)
            {
                if (i == 0)
                    {
                        headSumlist = sumlist = new ListNode(str[i] - '0');
                    }
                else
                    {
                        sumlist->next = new ListNode(str[i] - '0');
                        sumlist = sumlist->next;
                    }
            }
        return headSumlist;
    }

    //正确答案，不会溢出
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* dummyHead = new ListNode(0);
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* curr = dummyHead;
        int carry = 0;
        while (p != nullptr || q != nullptr)
            {
                int x = (p != nullptr) ? p->val : 0;
                int y = (q != nullptr) ? q->val : 0;
                int sum = carry + x + y;
                carry = sum / 10;
                curr->next = new ListNode(sum % 10);
                curr = curr->next;
                if (p != nullptr) p = p->next;
                if (q != nullptr) q = q->next;
            }
        if (carry > 0)
            {
                curr->next = new ListNode(carry);
            }
        return dummyHead->next;
    }
};

static void print(ListNode* head)
{
    do
        {
            std::cout << head->val << "->";
        }
    while ((head = head->next) != nullptr);
    std::cout << std::endl;
}

int main(int argc, char const* argv[])
{
    ListNode* l1head = nullptr;
    ListNode* l2head = nullptr;
    ListNode* l1 = nullptr;
    ListNode* l2 = nullptr;

    l1head = l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1 = l1->next;
    l1->next = new ListNode(3);
    l1 = l1->next;
    l1->next = nullptr;

    l2head = l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2 = l2->next;
    l2->next = new ListNode(4);
    l2 = l2->next;
    l2->next = nullptr;

    ListNode* sumlist = Solution::addTwoNumbers(l1head, l2head);
    print(sumlist);

    delete[] l1head;
    delete[] l2head;
    delete[] sumlist;
    return 0;
}
