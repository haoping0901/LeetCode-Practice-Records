class ExamTracker {
    // {time, index}
    map<int, long long> prefix_;
public:
    ExamTracker() {
        prefix_[0] = 0;
    }
    
    void record(int time, int score) {
        auto it = --prefix_.end();
        prefix_[time] = score + it->second;
    }
    
    long long totalScore(int startTime, int endTime) {
        // lower_bound(key) => >= key
        // upper_bound(key) => > key
        long long start = (--prefix_.lower_bound(startTime))->second;
        long long end = (--prefix_.upper_bound(endTime))->second;

        return end - start;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */