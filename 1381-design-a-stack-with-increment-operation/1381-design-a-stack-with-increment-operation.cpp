class CustomStack {
    vector<int> st_, add_;
    int top_;
public:
    CustomStack(int maxSize) {
        st_.resize(maxSize);
        add_.resize(maxSize);
        top_ = 0;
    }
    
    void push(int x) {
        if (top_ < st_.size())
            st_[top_++] = x;
    }
    
    int pop() {
        int ret;

        if (top_ == 0)
            return -1;

        --top_;
        ret = st_[top_] + add_[top_];
        if (top_ > 0)
            add_[top_ - 1] += add_[top_];
        add_[top_] = 0;

        return ret;
    }
    
    void increment(int k, int val) {
        int boundary = min(top_, k) - 1;
        
        if (boundary >= 0)
            add_[boundary] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */