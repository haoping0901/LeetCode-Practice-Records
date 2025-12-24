class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        // Target: longest subarray [i, j]
            // XOR of number of [i, j] == 0,
            // number of odd numbers equal to even numbers'
        // {{32b{x}, 32b{diff}}, index}
        unordered_map<long long, int> rec;
        int ans = 0, diff = nums.size(), x = 0;

        rec[1LL * x << 32 | diff] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            x ^= nums[i];
            if (nums[i] & 0x1)
                ++diff;
            else
                --diff;

            long long key = 1LL * x << 32 | diff;
            if (rec.find(key) != rec.end())
                ans = max(ans, i - rec[key]);
            else
                rec[key] = i;
        }

        return ans;
    }
};
// Input: [1, 5, 2, 4, 0]
// 4

// [3, 1, 3, 2, 0]
// x: 11, 10, 01, 11, 11
// cnt:
// {1, 0}, {2, 0}, {3, 0}, {3, 1}, {3, 2}