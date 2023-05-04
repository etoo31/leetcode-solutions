class MinStack {
private:
    int *arr;
    int size;
    int mini;
    int front;
    
public:
    MinStack() {
        size= 5;
        arr = new int[5];
        mini = 0;
        front = -1;
    }
    
    void push(int val) {
        front++;
        if (front == size)
            extendArray();
        arr[front] = val;
        if (arr[mini] > arr[front])
            mini = front;
        
    }
    void extendArray()
    {
        int *temp = new int[size*2];
        for (int i = 0 ; i < size; i++)
        {
            temp[i] = arr[i];
        }
        size = size*2;
        delete [] arr;
        arr = temp;
    }
    
    void pop() {
        if (front < 0)
        {
            cout << "can't pop";
        }
        else {
            if (mini == front)
            {
             calculateMin();   
            }
            front--;
        };
    }
    void calculateMin()
    {
      if ((front-1) < 0)
      {
          mini = 0;
      }
      else {
          mini = 0;
          for (int i = 0; i <= (front-1); i++)
          {
              if (arr[mini] > arr[i])
                  mini = i;
          }
      }
    }
    int top() {
        if (front < 0)
        {
            cout << "there is no elements in the stack";
        }
        else return arr[front];
        return -1;
    }
    
    int getMin() {
        if (front < 0)
        {
            cout << "no elements";
            return -1;
        }
        else return arr[mini];
        
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