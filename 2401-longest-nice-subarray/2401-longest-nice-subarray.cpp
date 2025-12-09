class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        // Target: longest nice sub arr
            // nice: n_i & n_j == 0, i != j
        // a & b == 0 => bit in a do not appear in b
        // c want to be nice to a and b => bit in c do not appear in a and b (a | b)

        // Sliding window
        // rec: rec the bit appeared in sub arr now
            // encounter element not nice => shrink the window by xor left element
            // until meet the cond.
        // For example: [1, 11, 1000, 110000, 1010], rec = 0
        // l = r = 0: rec |= 1 = 1
        // 1 (rec) & 11 -> not nice -> l point to 11, rec = 1 ^ 1 = 0
        // 11 & 1000 -> nice -> rec = 11 | 1000 = 1011
        // ...
        // 1011 & 1010 -> not nice -> rec = 1011 ^ 11 = 1000 => still not nice
        // 1000 ^ 1000 = 0 -> nice => rec |= 1010 = 1010

        int l = 0, r;
        int ret = 0, rec = 0;

        for (r = 0; r < nums.size(); ++r) {
            while ((rec & nums[r]) != 0)
                rec ^= nums[l++];
            rec |= nums[r];

            ret = max(ret, r - l + 1);
        }

        return ret;
    }
};