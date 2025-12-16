class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        // Input:
            // vec of num
            // window size m
        // Target: max product of first and last nums in window with size m
        long long ret = -10000000000;
        int max_n, min_n, i;

        max_n = min_n = nums[0];
        for (i = m - 1; i < nums.size(); ++i) {
            max_n = max(max_n, nums[i - m + 1]);
            min_n = min(min_n, nums[i - m + 1]);

            ret = max({ret, (long long)max_n * nums[i], (long long)min_n * nums[i]});
        }

        return ret;
    }
};