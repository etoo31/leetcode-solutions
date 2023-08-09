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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0 )
        {
            return nullptr;
        }
        while(lists.size() > 1)
        {
            vector<ListNode *>mergedList;
            for (int i = 0 ; i < lists.size(); i+=2)
            {
                ListNode *temp1 = lists[i];
                ListNode *temp2 = nullptr;
                if (i+1 != lists.size())
                {
                    temp2 = lists[i+1];
                }
                mergedList.push_back(mergeList(temp1,temp2));
            }
            lists.clear();
            lists = mergedList;
        }
        return lists[0];
        
    }
    ListNode * mergeList(ListNode * l1 , ListNode *l2)
    {
        
        ListNode * ans = nullptr;
        ListNode *ptr = nullptr;
        while (l1 != nullptr || l2 != nullptr)
        {
            int val;
            if (l1 == nullptr)
            {
                val = l2->val;
                l2 = l2->next;
            }
            else if (l2 == nullptr)
            {
                val = l1->val;
                l1 = l1->next;
            }
            else
            {
                if (l1->val < l2->val)
                {
                    val = l1->val;
                    l1 = l1->next;
                }
                else
                { 
                    val = l2->val;
                    l2 = l2->next;
                }
            }
            ListNode *temp = new ListNode(val);
            if (ans == nullptr)
            {
                ans = temp;
                ptr = temp;
            }
            else 
            {
                ptr->next = temp;
                ptr = ptr->next;
            }
        }
        return ans;
    }
    /*void printList(ListNode * t)
    {
        while (t)
        {
            cout << t->val << " ";
            t = t->next;
        }
        cout << endl;
    }*/
    
};