class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        // Target: check each window of s from queries qi can be transformed into
        // a palindrome string
            // each window can replace k alhpabet by any other alhpabet
        // prefix sum: prefix, record each alphabet's appearance frequency by xor op.
        // for each bit in an integer (0 bit stands for 'a', etc.)
        // for each query qi
            // get the freq. of each alpha.
            // Get the number of bit 1 nb
            // Check if nb / 2 > k
                // True: false
        int n = s.length(), m = queries.size();
        vector<int> prefix(n + 1);
        vector<bool> ans(m);

        for (int i = 0; i < n; ++i)
            prefix[i + 1] ^= prefix[i] ^ (1 << (s[i] - 'a'));
        
        for (int i = 0; i < m; ++i) {
            int sum = prefix[queries[i][1] + 1] ^ prefix[queries[i][0]];
            int n_bit = 0;

            for (int j = 0; j < 26; ++j) {
                n_bit += (sum & 0x1);
                sum >>= 1;
            }

            if ((n_bit >> 1) <= queries[i][2])
                ans[i] = true;
        }

        return ans;
    }
};
// Input: "abcd", [[1, 3, 2]]
// Output: ["True"]
// prefix (represent by bit): [0, 1, 11, 111, 1111]
// {k, max affordable}:
// {1, 3}, {2, 5}
