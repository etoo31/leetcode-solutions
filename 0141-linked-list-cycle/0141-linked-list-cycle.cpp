/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * fastRunner = head;
        ListNode * slowRunner = head;
        if(fastRunner)
            fastRunner = head->next;
        while(fastRunner != nullptr && fastRunner->next != nullptr && slowRunner != nullptr)
        {
            if (fastRunner == slowRunner)return true;
            slowRunner = slowRunner -> next;
            fastRunner = fastRunner->next->next;
        }
        return false;
    }
};