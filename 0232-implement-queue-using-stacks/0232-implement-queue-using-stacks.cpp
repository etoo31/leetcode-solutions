class MyQueue {
    stack<int>st , queue;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        if (queue.empty())
        {
            transferElements();
        }
        int val = queue.top();
        queue.pop();
        return val;
        
    }
    void transferElements()
    {
        while(!st.empty())
        {
            queue.push(st.top());
            st.pop();
        }
    }
    
    
    int peek() {
         if (queue.empty())
        {
            transferElements();
        }
        int val = queue.top();
        return val;
        
    }
    
    bool empty() {
        return (st.size() == 0 && queue.size() == 0) ;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */