class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int idx_diff, int val_diff) {
        // Input:
            // nums: vec of num, size = n
        // Target:
            // abs(i - j) >= idx_diff
            // abs(ni - nj) >= val_diff
        // Two pointers
        // Iterate all num, pointers {l, r} = {0, idx_diff}
            // rec the min / max
            // Check if min - cur / max - cur > val_diff
        int r = idx_diff;
        int min_idx, max_idx;

        min_idx = max_idx = 0;

        for (r = idx_diff; r < nums.size(); ++r) {
            if (nums[r - idx_diff] < nums[min_idx])
                min_idx = r - idx_diff;
            else if (nums[r - idx_diff] > nums[max_idx])
                max_idx = r - idx_diff;

            if (abs(nums[r] - nums[min_idx]) >= val_diff)
                return {min_idx, r};
            else if (abs(nums[r] - nums[max_idx]) >= val_diff)
                return {max_idx, r};
        }

        return {-1, -1};
    }
};