class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map <int, bool> cnt;
        
        for (int i=0; i<nums.size(); i++) {
            if (cnt.count(nums[i]))
                return true;
            cnt[nums[i]] = true;
        }
        return false;
    }
};