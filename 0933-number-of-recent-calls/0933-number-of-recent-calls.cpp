class RecentCounter {
    int cnt=0, idx=0, pin_time=-2999;
    vector<int> time_rec;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        time_rec.push_back(t);

        while (time_rec.at(idx)+3000 < t) {
            idx++;
        }
        return time_rec.size()-idx;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */