class RandomizedSet {
    // unorder_map record the existence of specific number
    // vector for the random number in specific range
    unordered_map<int, int> nums;
    vector<int> nums_rec;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (nums.count(val) > 0) {
            return false;
        } else {
            nums_rec.push_back(val);
            nums[val] = nums_rec.size()-1;

            return true;
        }
    }
    
    bool remove(int val) {
        if (nums.count(val) > 0) {
            // erase the value in vector by value in the end of the vector
            nums_rec.at(nums[val]) = nums_rec.back();

            // update the position information in the unordered_map
            nums[nums_rec.back()] = nums[val];
            nums_rec.pop_back();
            nums.erase(val);
            
            return true;
        } else {
            return false;
        }
    }
    
    int getRandom() {
        return nums_rec.at(rand() % nums_rec.size());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */