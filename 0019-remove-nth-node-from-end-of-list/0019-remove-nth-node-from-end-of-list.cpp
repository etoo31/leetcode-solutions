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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pointer = head;
        int c = 0;
        while(pointer != nullptr)
        {
            pointer = pointer->next;
            c++;
        }
        if(n == c)
        {
            head = head->next;
            return head;
        }
        pointer = head;
        while(pointer != nullptr)
        {
            if (c == n+1)
            {
                pointer->next = (pointer->next)->next;
                break;
            }
            pointer = pointer->next;
            c--;
        }
        return head;
        
    }
};