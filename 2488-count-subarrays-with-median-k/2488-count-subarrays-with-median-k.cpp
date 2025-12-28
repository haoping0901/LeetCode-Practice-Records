class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        // Target: number of non-empty subarrays that have median k
        unordered_map<int, int> rec;
        int ans = 0, sum = 0;
        bool found = false;

        rec[0] = 1;
        for (const int n : nums) {
            if (n == k)
                found = true;
            else if (n > k)
                ++sum;
            else
                --sum;
            
            if (found == false)
                ++rec[sum];
            else
                ans += rec[sum] + rec[sum - 1];
        }

        return ans;
    }
};