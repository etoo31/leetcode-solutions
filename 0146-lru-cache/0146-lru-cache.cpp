class Node{
public:
    int key;
    int val;
    Node* next;
    Node* prev;
public:
    Node(int key , int val):key(key), val(val){
     next = nullptr;
     prev = nullptr;
    }    
};

class LRUCache {
public:
    map<int, Node *>mp;
    Node * left;
    Node* right;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
        left = nullptr;
        right = nullptr;
    }
    //remove node from the list
    void removeNode(Node* node) {
            if (node == right && node == left) {
            // Only one node in the cache
            right = left = nullptr;
            } else if (node == right) {
                right = right->prev;
                right->next = nullptr;
            } else if (node == left) {
                left = left->next;
                left->prev = nullptr;
            } else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
    }

    //insert node to the right
    void insertNode(Node *node)
    {
        if (right == nullptr)
        {
            left = right = node;
            return;
        }
        right->next = node;
        node->prev = right;
        right = node;
    }
    int get(int key) {
        if (mp.find(key) != mp.end())
        {
            removeNode(mp[key]);
            insertNode(mp[key]);
            return mp[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
        {
            removeNode(mp[key]);
            mp[key]->val = value;
            insertNode(mp[key]);
            return;
        }
        Node * node = new Node(key , value);
        mp[key] = node;
        insertNode(node);
        //viewList();
        if (mp.size() > cap)
        {
            Node *temp = left;
            removeNode(left);
            mp.erase(temp->key);
            delete temp;
        }
        //viewList();
    }
    /*void viewList()
    {
        Node *temp = left;
        while(temp)
        {
            cout << temp->key << " "<< temp->val << " " << endl; 
            temp = temp->next;
        }
        cout << "-----------------------------------------------\n";
    }*/
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */