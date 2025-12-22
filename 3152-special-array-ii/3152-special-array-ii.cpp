class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        // Special: every pair of the element's adjacent elements contains two
        // numbers with different parity.
        // Target: queries' answer
        // prefix sum:
        int n = nums.size(), nq = queries.size();
        vector<bool> ans(nq);
        vector<int> prefix(n);

        // record the amount of elements pair that has the same parity
        // for each num from range [0, n] to an arr. prefix
        for (int i = 1; i < n; ++i)
            prefix[i] += prefix[i - 1] + ((nums[i - 1] & 0x1) ==
                                          (nums[i] & 0x1));

        // For each queries in range [i, j]
            // if prefix[j] - prefix[i] > 0 => rec. false to ans
        for (int i = 0; i < nq; ++i) {
            if (prefix[queries[i][1]] - prefix[queries[i][0]] == 0)
                ans[i] = true;
        }

        return ans;
    }
};
// Input:
// nums:    [1, 2, 3, 5, 6]
// queries: [[0, 2], [2, 3], [3, 4]]
// prefix:  [0, 0, 0, 1, 1]
// Output:  [true, false, true]