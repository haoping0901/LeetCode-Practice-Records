class Solution {
public:
    int minimumSum(vector<int>& nums) {
        // Target: find n(i, j, k) where ni < nj && nk < nj, i < j < k
        // Brute force:
        // check the combination of j in [1, n - 1] of nums
        vector<int> suffix(nums);
        int i, j, k;
        int n = nums.size(), ret = 300000000;
        int ni, nk;

        for (i = n - 2; i >= 0; --i)
            suffix[i] = min(suffix[i + 1], suffix[i]);

        for (j = 1; j < n - 1; ++j) {
            ni = min(ni, nums[j - 1]);
            
            if (ni < nums[j] && suffix[j + 1] < nums[j])
                ret = min(ret, ni + nums[j] + suffix[j + 1]);
        }

        return ret == 300000000 ? -1 : ret;
    }
};