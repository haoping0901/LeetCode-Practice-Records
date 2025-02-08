class MedianFinder {
    priority_queue<int> max_heap_;
    priority_queue<int, vector<int>, greater<int>> min_heap_;
    unsigned int cnt_ = 0;

    bool IsOdd(unsigned int cnt) const {
        return cnt & 0x1;
    }
public:
    MedianFinder() {
        
    }

    /**
     * @brief Return the mudian.
     * @details 
     * 
     * @param[in] num Integer from data stream to be added.
     */
    void addNum(int num) {
        // Add numbers to the sequence → A container is needed to store the 
        // sequence.
            // Use a min_heap and a max_heap, ensuring that the size 
            // difference between them does not exceed 1.
            // Additionally, the top of min_heap must always be greater than 
            // or equal to the top of max_heap.
        ++cnt_;
        
        // Process of adding a number:  
            // 1. Maintain the heap sizes.
            // 2. Determine which heap to insert into.
        if (min_heap_.size() < max_heap_.size()) {
            // Adding a number to min_heap:  
            // Ensure that the number is greater than max_heap.top() before 
            // inserting it.  
            if (max_heap_.top() > num) {
                min_heap_.push(max_heap_.top());
                max_heap_.pop();
                max_heap_.push(num);
            } else {
                min_heap_.push(num);
            }
        } else {
            // Adding a number to max_heap:
            if (!min_heap_.empty() && min_heap_.top() < num) {
                max_heap_.push(min_heap_.top());
                min_heap_.pop();
                min_heap_.push(num);
            } else {
                max_heap_.push(num);
            }
        }
    }
    
    /**
     * @brief Return the mudian.
     * @details 
     * 
     * @return double the medeian.
     */
    double findMedian() {
        // Determine how to obtain the median based on the sizes of the two 
        // heaps.
        // If cnt_ is odd, decide which top value to return based on the size 
        // of max_heap.
        // If cnt_ is even, return the average of the top values from both 
        // heaps.  
        if (IsOdd(cnt_)) {
            if (max_heap_.size() > min_heap_.size()) {
                return max_heap_.top();
            } else {
                return min_heap_.top();
            }
        } else {
            return (static_cast<double>(min_heap_.top()) + max_heap_.top()) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */