class MinStack {
private:
    pair<int,int> *arr; //val , miniIndex
    int size;
    int front;
    
public:
    MinStack() {
        size = 5;
        arr = new pair<int,int>[size];
        front = -1;
        
    }
    
    void push(int val) {
        if (front == size-1)
        {
            extendArray();
        }
        if (front != -1)
        {
            if (arr[front].second > val)
            {
                arr[++front] = {val , val};
            }
            else
            {
                int mini = arr[front].second;
                arr[++front] = {val , mini};
                
            }
        }
        else {
            arr[++front] = {val , val};
        }
        
    }
    void extendArray()
    {
        pair<int , int> * newArr = new pair<int , int>[size*2];
        for (int i = 0 ; i < size; i++)
        {
            newArr[i] = arr[i];
        }
        size = size*2;
        pair<int , int> * temp = arr;
        arr = newArr;
        delete [] temp;
    }
    
    void pop() {
        if (front == -1)
        {
            cout << "Stack is empty" << endl;
        }
        front--;
    }
    
    int top() {
        if (front == -1)
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return arr[front].first;
        
    }
    
    int getMin() {
        if (front == -1)
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return arr[front].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */