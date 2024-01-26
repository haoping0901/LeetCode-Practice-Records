class MinStack {
    int s_ptr, min_num, min_ptr;
    int s[30000], min_s[30000];
public:
    MinStack() {
        s_ptr = 0;
        min_ptr = 0;
        min_num = ~(1<<31);
    }
    
    void push(int val) {
        s[s_ptr] = val;
        s_ptr++;

        if (val < min_num) 
            min_num = val;
        
        min_s[min_ptr] = min_num;
        min_ptr++;
    }
    
    void pop() {
        s_ptr--;
        min_ptr--;

        if (s_ptr == 0) 
            min_num = ~(1<<31);
        else
            min_num = min_s[min_ptr-1];
    }
    
    int top() {
        return s[s_ptr-1];
    }
    
    int getMin() {
        return min_s[min_ptr-1];
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