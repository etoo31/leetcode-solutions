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
    void reorderList(ListNode* head) {
        ListNode* ans = nullptr;
        ListNode* pointer = new ListNode;
        pointer->val = head->val;
        pointer->next = head->next;
        int counter = 0;
        while(pointer != nullptr)
        {
            ListNode * temp = new ListNode;
            temp->val = pointer->val;
            temp->next = ans;
            ans = temp;
            pointer = pointer->next;
            counter++;
        }
        bool odd = (counter%2);
        counter = ceil(counter/2.0);
        //cout << counter << endl
        ListNode *newList = nullptr;
        ListNode *p = head;
        while(counter--)
        {
            ListNode *temp1 = new ListNode;
            temp1->val = p->val;
            temp1->next = nullptr;
            p = p->next;
            
            ListNode *temp2 = new ListNode;
            temp2->val = ans->val;
            temp2->next = nullptr;
            ans = ans->next;
            
            if (newList == nullptr)
            {
                newList = temp1;
                pointer = temp1;
            }
            else 
            {
                pointer->next = temp1;
                pointer = pointer->next;
            }
            if (odd && counter == 0)break;
            pointer->next = temp2;
            pointer = pointer->next;
            
        }
        head->val = newList->val;
        head->next = newList->next;
        while(newList != nullptr)
        {
            cout << newList->val << " ";
            newList = newList->next;
        }
        
        
    }
};