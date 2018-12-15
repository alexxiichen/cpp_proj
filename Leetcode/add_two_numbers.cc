#include <iostream>

struct ListNode
{
    int       val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
  public:
    // fuck 这里理解错了题意，是倒序的
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        unsigned int value1 = 0;
        unsigned int value2 = 0;
        unsigned int sum    = 0;
        do
        {
            value1 = value1 * 10 + l1->val;
        } while ((l1 = l1->next) != nullptr);
        std::cout << value1 << std::endl;

        do
        {
            value2 = value2 * 10 + l2->val;
        } while ((l2 = l2->next) != nullptr);
        std::cout << value2 << std::endl;

        sum = value1 + value2;
        std::cout << sum << std::endl;
        ListNode* headSumlist = nullptr;
        ListNode* sumlist     = nullptr;
        char      str[256];
        sprintf(str, "%u", sum);
        std::cout << str << std::endl;

        for (int i = 0; str[i] != '\0'; i++)
        {
            if (i == 0)
            {
                headSumlist = sumlist = new ListNode(str[i] - '0');
                // sumlist               = sumlist->next;
            }
            else
            {
                sumlist->next = new ListNode(str[i] - '0');
                sumlist       = sumlist->next;
            }
        }
        return headSumlist;
    }
};

static void print(ListNode* head)
{
    do
    {
        std::cout << head->val << "->";
    } while ((head = head->next) != nullptr);
    std::cout << std::endl;
}

int main(int argc, char const* argv[])
{
    ListNode* l1head = nullptr;
    ListNode* l2head = nullptr;
    ListNode* l1     = nullptr;
    ListNode* l2     = nullptr;

    l1head = l1 = new ListNode(2);
    l1->next    = new ListNode(4);
    l1          = l1->next;
    l1->next    = new ListNode(3);
    l1          = l1->next;
    l1->next    = nullptr;

    l2head = l2 = new ListNode(5);
    l2->next    = new ListNode(6);
    l2          = l2->next;
    l2->next    = new ListNode(4);
    l2          = l2->next;
    l2->next    = nullptr;

    ListNode* sumlist = Solution::addTwoNumbers(l1head, l2head);
    print(sumlist);

    delete[] l1head;
    delete[] l2head;
    delete[] sumlist;
    return 0;
}
