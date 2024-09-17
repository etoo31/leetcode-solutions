class DinnerPlates {
    vector<stack<int>>stacks;
    set<int>s , take;
    int maxi;
public:
    DinnerPlates(int capacity) {
        maxi = capacity;
    }
    
    void push(int val) {
        int index = getStackIndex();
        if (index == -1)
        {
            stack<int>temp;
           
            stacks.push_back(temp);
            index = stacks.size()-1;
            
             if(temp.size() + 1 < maxi)
                s.insert(index);
        }
        stacks[index].push(val);
        take.insert(index);
    }
    int getStackIndex()
    {
        if (s.size() == 0)return -1;
        else
        {
            int index = *s.begin();
           // cout << "Index "<< index << endl;
            if((stacks[index].size()+1) == maxi)
            {
                s.erase(s.begin());
            }
            return index;
        }
    }
    
    int pop() {
        //check();
        int index = getNonEmptyStack();
        if (index == -1)return -1;
        int removedItem = -1;
        
        if (stacks[index].size()){
            removedItem = stacks[index].top();
            stacks[index].pop();
        }
        s.insert(index);
        return removedItem;
    }
    int getNonEmptyStack()
    {
        if(take.size() ==0)return -1;
        else 
        {
            int index = *prev(take.end());
            if (stacks[index].size() -1 == 0)
            {
                take.erase(prev(take.end()));
            }
            return index;
        }
    }
    
    // void check()
    // {
    //     for (auto x : take)
    //     {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    
    int popAtStack(int index) {
       // check();
        if(stacks.size() == 0 || index >= stacks.size())return -1;
        if(stacks[index].size() == 0)
        {
            return -1;
        }
        int removedItem = stacks[index].top();
        stacks[index].pop();
        s.insert(index);
        if (stacks[index].size() == 0)
        {
            auto it = find(take.begin() , take.end() , index);
            if (it != take.end())
            {
                take.erase(it);
            }
        }
        
        return removedItem;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */