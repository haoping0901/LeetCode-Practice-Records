class SmallestInfiniteSet {
    int _min;
    set<int> added_int;
public:
    SmallestInfiniteSet() {
        _min = 1;
    }
    
    int popSmallest() {
        if (added_int.empty()) {
            return _min++;
        } else {
            int ret = *added_int.begin();
            added_int.erase(added_int.begin());
            return ret;
        }
    }
    
    void addBack(int num) {
        if (_min > num && added_int.find(num) == added_int.end()) {
            added_int.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */