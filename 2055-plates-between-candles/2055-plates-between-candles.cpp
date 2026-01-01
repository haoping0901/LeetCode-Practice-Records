class Solution {
public:
    int BinarySearch(const vector<pair<int, int>>& prefix, const vector<int>& q,
                     int target) {
        int l = q[0] + 1, r = q[1] + 1, m;

        while (l <= r) {
            m = l + ((r - l) >> 1);

            if (prefix[m].second >= target)
                r = m - 1;
            else
                l = m + 1;
        }

        return l;
    }

    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        // Target: number of plates between candles of each queries
        // prefix sum p of plate and candle for each character {sp, sc} => O(n)
        // For each queries q in range [l, r] => O(q), q == queries.length()
            // Find the first pn whose sc > pl's sc (binary seach => O(log(n)),
                // n == s.length())
            // Find the last pm whose sc > pn's sc (binary search => O(log(n)))
        int n = s.length(), qn = queries.size();
        vector<pair<int, int>> prefix(n + 1, {0, 0});
        vector<int> ans(qn);

        for (int i = 0; i < n; ++i) {
            prefix[i + 1].first += prefix[i].first + (s[i] == '*');
            prefix[i + 1].second += prefix[i].second + (s[i] == '|');
        }

        for (int i = 0; i < qn; ++i) {
            int start_candle = prefix[queries[i][0]].second + 1;
            int end_candle = prefix[queries[i][1] + 1].second;

            if (end_candle <= start_candle) {
                ans[i] = 0;
            } else {
                int start_idx = BinarySearch(prefix, queries[i], start_candle);
                int end_idx = BinarySearch(prefix, queries[i], end_candle);
                ans[i] = prefix[end_idx].first - prefix[start_idx].first;
            }
        }

        return ans;
    }
};
// Input
// s: "*||*||*"
// queries: [[2, 6], [0, 3]]
// Output: [[1, 0]]