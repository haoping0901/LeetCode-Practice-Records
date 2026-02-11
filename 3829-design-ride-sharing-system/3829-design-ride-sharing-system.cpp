class RideSharingSystem {
    deque<int> riders_;
    deque<int> drivers_;
    unordered_set<int> valid_;
public:
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        riders_.push_back(riderId);
        valid_.insert(riderId);
    }
    
    void addDriver(int driverId) {
        drivers_.push_back(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while (!riders_.empty() && valid_.find(riders_.front()) == valid_.end())
            riders_.pop_front();

        if (!riders_.empty() && !drivers_.empty()) {
            vector<int> ret({drivers_.front(), riders_.front()});
            riders_.pop_front();
            drivers_.pop_front();

            return ret;
        } else {
            return {-1, -1};
        }
    }
    
    void cancelRider(int riderId) {
        valid_.erase(riderId);
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */