/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node* , Node* >mp;
        Node* temp = head;
        Node* ans  = nullptr;
        Node* prev = nullptr;
        //first pass
        while(head != nullptr)
        {
            Node * newNode = new Node(head->val);
            mp[head] = newNode;
            
            if (!ans)
            {
                ans = newNode;
            }
            else 
            {
                prev->next = newNode;
            }
            prev = newNode;
            head = head->next;
        }
        Node *ptr = ans;
        //second pass
        while(temp)
        {
            if (temp->random)
            {
                ptr->random = mp[temp->random];
            }
            ptr = ptr->next;
            temp = temp->next;
        }
        return ans;
        
    }
};