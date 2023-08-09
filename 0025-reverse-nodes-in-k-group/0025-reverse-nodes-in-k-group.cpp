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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* groupPrev = new ListNode(0, head);
        ListNode* dummy = groupPrev;

        while (true) {
            ListNode* kth = getKth(groupPrev, k);
            if (kth == nullptr)
                break;
            ListNode *nextGroup = kth->next;
            ListNode* prev = kth->next;
            ListNode* curr = groupPrev->next;
            while (curr != nextGroup) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            ListNode * temp = groupPrev->next;
            //cout << "last : " << temp->val << endl;
            groupPrev->next = prev;
            groupPrev = temp;
            
        }
        return dummy->next;
        
    }
    ListNode *getKth(ListNode * curr , int k)
    {
        while (curr && k--)
        {
            curr = curr->next;
        }
        return curr;
    }
};