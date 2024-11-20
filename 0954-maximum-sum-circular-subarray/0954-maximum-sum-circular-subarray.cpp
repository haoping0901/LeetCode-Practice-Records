class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        // kadane's algo.
        int cur_min = 0, cur_max = 0;
        int max_sum = nums[0], min_sum = nums[0], sum = 0;
        for (const int&n: nums) {
            cur_max = max(cur_max + n, n);
            max_sum = max(max_sum, cur_max);
            cur_min = min(cur_min + n, n);
            min_sum = min(min_sum, cur_min);

            sum += n;
        }

        return max_sum > 0 ? max(max_sum, sum - min_sum) : max_sum;
    }
};