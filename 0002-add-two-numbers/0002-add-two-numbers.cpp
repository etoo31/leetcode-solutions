/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp = l1;
        int c1 = 0;
        while(temp != nullptr)
        {
            c1++;
            temp = temp->next;
        }
        temp = l2;
        int c2 = 0;
        while(temp)
        {
            c2++;
            temp = temp->next;
        }
        if (c1 < c2)
        {
            ListNode* x = l2;
            l2 = l1;
            l1 = x;
        }
        temp = l1;
        while (temp != nullptr && l2)
        {
            temp->val = temp->val + l2->val;
            l2 = l2->next;
            temp = temp->next;
        }
        temp = l1;
        int remainder = 0;
        while (temp != nullptr)
        {
            temp->val = temp->val + remainder;
            remainder = temp->val/10;
            temp->val = temp->val%10;
            if (temp->next == nullptr)
            {
                if (remainder != 0)
                {
                    ListNode * newNode = new ListNode;
                    newNode->next = nullptr;
                    temp->next = newNode;
                }
            }
            temp = temp->next;
        }
        return l1;
    }
};