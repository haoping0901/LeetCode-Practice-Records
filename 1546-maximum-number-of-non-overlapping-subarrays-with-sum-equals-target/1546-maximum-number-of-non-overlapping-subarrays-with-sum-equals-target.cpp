class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        // max(s[i] - s[j] == target), i > j
        // Target: max non-empty non-overlapping subarrays that sum == target
        // prefix & suffix vector rec. the sum of ans. for each index
        // Iterate twice, one from the beginning, other from the end
        // Each element record the current sum to an unordered_map
            // {sum, index}
            // For each sum, check if sum - target exist
                // If so, record the ans to prefix / suffix
        unordered_map<int, int> rec;
        int n = nums.size(), ans = 0, sum;
        vector<int> prefix(n), suffix(n);

        sum = 0;
        rec[0] = -1;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];

            auto it = rec.find(sum - target);
            if (it != rec.end()) {
                ++prefix[i];
                if (i > 0)
                    prefix[i] += prefix[i - 1];
                
                rec.clear();
                sum = 0;
            } else {
                if (i > 0)
                    prefix[i] = prefix[i - 1];
            }

            rec[sum] = i;
        }

        sum = 0;
        rec.clear();
        rec[0] = n;
        for (int i = n - 1; i >= 0; --i) {
            sum += nums[i];

            auto it = rec.find(sum - target);
            if (it != rec.end()) {
                ++suffix[i];
                if (i < n - 1)
                    suffix[i] += suffix[i + 1];
                rec.clear();
                sum = 0;
            } else {
                if (i < n - 1)
                    suffix[i] = suffix[i + 1];
            }

            rec[sum] = i;
        }

        for (int i = 0; i < n - 1; ++i)
            ans = max(ans, prefix[i] + suffix[i + 1]);

        return ans;
    }
};
// Input: [-5, 2, 3, -1, 4], target = 3
// Output: 2 ([3], [-1, 4])