class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // good: [i, j], abs(ni - nj) == k
        // Target: max sum of good subarray
        // |ni - nj| == k
        // nj - k == ni == nj + k
        unordered_map<int, long long> rec;
        long long ans = LLONG_MIN, sum = 0;

        for (const int n : nums) {
            auto it = rec.find(n + k);
            if (it != rec.end())
                ans = max(ans, sum + n - it->second);

            it = rec.find(n - k);
            if (it != rec.end())
                ans = max(ans, sum + n - it->second);
            
            it = rec.find(n);
            if (it == rec.end() || sum < it->second)
                rec[n] = sum;

            sum += n;
        }

        return ans == LLONG_MIN ? 0 : ans;
    }
};
// Input: [1, 2, 3, 4, 5], k = 2
// Output: 8