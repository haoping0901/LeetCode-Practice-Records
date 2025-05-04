class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> avg(nums.size(), -1);
        unsigned long long sum = 0;
        unsigned denominator = (k << 1) + 1;    /* 2k + 1*/
        size_t head_idx = 0;
        size_t avg_idx = k;
        size_t start_cal_idx = k << 1;  /* 2k */
        size_t idx;
        // input: nums arr, average of arr[i +- k, inclusive]
        
        // index that start calculating averge: 2k
        // index filled with average: k = 2k - k;

        if (denominator == 0)
            return avg;

        for (idx = 0; idx < nums.size(); ++idx) {
            sum += nums[idx];
            if (idx >= start_cal_idx) {
                avg[avg_idx] = sum / denominator;

                ++avg_idx;
                sum -= nums[head_idx];
                ++head_idx;
            }
        }

        return avg;
    }
};