class FrontMiddleBackQueue {
    // divide the FMB queue into two part: q1, q2
    // keep size(q2) = q_size_ / 2, size(q1) = q_size_ / 2 + q_size_ % 2
    deque<int> q1_, q2_;
public:
    FrontMiddleBackQueue() {

    }

    void BalanceQueueSize() {
        if (q1_.size() > q2_.size()) {
            q2_.push_front(q1_.back());
            q1_.pop_back();
        } else if (q2_.size() > q1_.size() + 1) {
            q1_.push_back(q2_.front());
            q2_.pop_front();
        }
    }
    
    void pushFront(int val) {
        q1_.push_front(val);
        BalanceQueueSize();
    }
    
    void pushMiddle(int val) {
        if (q1_.size() < q2_.size())
            q1_.push_back(val);
        else
            q2_.push_front(val);
    }
    
    void pushBack(int val) {
        q2_.push_back(val);
        BalanceQueueSize();
    }
    
    int popFront() {
        int ret;
        if (q2_.empty())
            return -1;

        if (q1_.empty()) {
            ret = q2_.front();
            q2_.pop_front();
        } else {
            ret = q1_.front();
            q1_.pop_front();
        }
        BalanceQueueSize();

        return ret;
    }
    
    int popMiddle() {
        int ret;
        if (q2_.empty())
            return -1;

        if (q1_.size() == q2_.size()) {
            ret = q1_.back();
            q1_.pop_back();
        } else {
            ret = q2_.front();
            q2_.pop_front();
        }

        return ret;
    }
    
    int popBack() {
        int ret;
        if (q2_.empty())
            return -1;

        ret = q2_.back();
        q2_.pop_back();
        BalanceQueueSize();

        return ret;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */