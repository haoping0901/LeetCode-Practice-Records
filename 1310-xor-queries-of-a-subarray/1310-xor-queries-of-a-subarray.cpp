class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // query[i, j]: compute the xor of elements in range [i, j]
        // Target: ans. vector of all queries
        int n = arr.size(), n_q = queries.size();
        vector<int> ans(n_q);
        vector<int> prefix(n + 1);
        // prefix sum
        // for each n
            // comulate the result after xor from the beginning of arr
            // and record it to an arr. prefix
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] ^ arr[i];

        // for each query i in range [i, j]
        for (int i = 0; i < n_q; ++i)
            // store the result of prefix[j + 1] xor prefix[i] to ans[i]
            ans[i] = prefix[queries[i][1] + 1] ^ prefix[queries[i][0]];

        return ans;
    }
};
// Input:
// arr:     [1, 2, 3] (1, 10, 11)
// queries: [[0, 1], [1, 2]]
// Output: [3 (11), 1]
// prefix: [0, 1, 11, 0]
// i = 0: ans = prefix[2] ^ prefix[0] = 3 (11)
// i = 1: ans = prefix[3] ^ prefix[1] = 1