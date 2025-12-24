class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        // Target: number of beautiful subarray
        // Beautiful array: num. in [i, j] == 0 after applying specific operation
        // {result of xor from the start, counter} rec
        // Use int x var. to rec. the result of xor each num.
        // Iterate all num.
            // ans += rec[x]
            // for each num, add the result of xor num to a var. x
            // Add rec[x] by 1
        unordered_map<int, int> rec;
        long long ans = 0;
        int x = 0;

        ++rec[0];
        for (const int n : nums) {
            x ^= n;
            ans += rec[x];
            ++rec[x];
        }

        return ans;
    }
};
// Input: [2, 2, 1, 4, 5]
// Output: 3
// rec[0] = 1
// 2,   x = 2 (10),     ans = 0,    rec[2] = 1
// 2,   x = 0,          ans = 1,    rec[0] = 2
// 1,   x = 1,          ans = 1,    rec[1] = 1
// 4,   x = 5 (101),    ans = 1,    rec[5] = 1
// 5,   x = 0,     ,    ans = 3,    rec[0] = 3

