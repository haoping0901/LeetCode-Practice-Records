class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // n = 5, i = 2 -> sun 3 (0~2) >= 5-2-1= sum 2 (3~4), 0 <= i < n-1
        // Compute the cumulative sum of the array elements.
        size_t n_nums = nums.size();
        vector<long long> sum_from_left(n_nums, 0);

        for (size_t l=0; l<n_nums; ++l) {
            if (l == 0) {
                sum_from_left[l] = nums[l];
            } else {
                sum_from_left[l] += nums[l] + sum_from_left[l-1];
            }
        }

        // Iteratively subtract the value of elements from the beginning of 
        // the array and check whether the result satisfies the condition.
        int ret = 0;
        for (size_t l=0, r=n_nums-1; l<r; ++l) {
            sum_from_left[r] -= nums[l];

            if (sum_from_left[l] >= sum_from_left[r]) {
                ++ret;
            }
        }

        return ret;
    }
};