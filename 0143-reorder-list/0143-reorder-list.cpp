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
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr && fast->next != nullptr)
                fast = fast->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode*prev = nullptr;
        while(second != nullptr)
        {
            ListNode *temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }
        second = prev;
        ListNode* first= head;
        while(first != nullptr && second != nullptr)
        {
            ListNode *temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;    
            
        }
        
        /*while(head != nullptr)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
        while(second != nullptr)
        {
            cout << second->val << " ";
            second = second->next;
        }
        cout << endl;*/
        
        
    }
};