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
    ListNode* deleteDuplicates(ListNode* head) {
       ListNode * temp = head;
       ListNode * last = head;
        while(temp != nullptr)
        {
            int val = -200;
            //cout << "last : " << last->val << endl;
            //cout << "temp: " << temp->val << endl;
            while(temp->next != nullptr && temp->val == temp->next->val)
            {
                //cout << "i'm in" << endl;
                val = temp->val;
                //cout << val << endl;
                temp = temp->next;
            }
            //cout << "------------------------------------------\n";
            if (last->val == val)
            {
                head = temp->next;
                temp = temp->next;
                last = head;
                continue;
            }
            else if (val != -200)
            {
                last->next =temp->next;
                temp = temp->next;
                continue;
            }
            else {
                last = temp;
                temp = temp->next;
            }
        }
        return head;  
    }
};