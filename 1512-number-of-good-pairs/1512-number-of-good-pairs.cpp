class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // Target: find number of good pair
            // good: nums[i] == nums[j], i < j
        unordered_map<int, int> rec;
        int ret = 0;

        for (const int& n: nums)
            ret += rec[n]++;

        return ret;
    }
};