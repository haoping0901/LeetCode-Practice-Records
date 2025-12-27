class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        // Target: max sum of the subarray
            // the size of subarray is divisible by k
        // max(s[j + 1] - s[i]) => max(s[j + 1]), min(s[i])
        // (j + 1 - i) mod k == 0
        // {(j + 1) % k, min(s[i])}
        unordered_map<int, long long> rec;
        long long sum = 0, ans = LLONG_MIN;

        rec[0] = 0;
        for (int i = 0, remainder = 1; i < nums.size(); ++i, ++remainder) {
            sum += nums[i];

            remainder %= k;
            auto it = rec.find(remainder);
            if (it == rec.end()) {
                rec[remainder] = sum;
            } else {
                ans = max(ans, sum - it->second);
                it->second = min(it->second, sum);
            }
        }

        return ans;
    }
};
