class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        // Target: min sum of subarray with size [l, r], sum > 0
        // min(s[j + 1] - s[i]) => min(s[j + 1]) - max(s[i]), l <= j + 1 - i <= r
        // prefix sum with sliding window and set
        // for each element ni, record the sum in [i - r + 1, i - l + 1] into a set
            // O(n)
        // Find and rec the min of the sum of s[i + 1] and s[i - r + 1, .. , s[i - l + 1]]
            // O(log(r))
        multiset<int> rec;
        int n = nums.size(), ans = INT_MAX;
        vector<int> prefix(n + 1);

        for (int j = 1; j <= n; ++j) {
            prefix[j] = prefix[j - 1] + nums[j - 1];

            if (j < l)
                continue;
            rec.insert(prefix[j - l]);
            
            auto it = rec.lower_bound(prefix[j]);
            if (it != rec.begin())
                ans = min(ans, prefix[j] - *--it);

            if (j >= r)
                rec.erase(rec.find(prefix[j - r]));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
// Input:
// nums: [1, -2, 3, -4]
// {l, r}: {2, 3}
// Output: 1
// prefix sum: [0, 1, -1, 2, -2]