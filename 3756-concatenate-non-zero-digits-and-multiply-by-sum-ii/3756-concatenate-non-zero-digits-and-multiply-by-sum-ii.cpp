static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        // Input:
            // str s (len m)
            // queries: qi = [li, ri]
        // Target: 
            // form new integer ni from s with range in queries qi
                // Each integer does not contains zero
                // If substring has no non-zero digit, then return zero
            // ansi = (ni * digit_sum(ni)) mod 1e9 + 7
        int m = s.length();
        vector<int> new_n(m + 1), sum_d(m + 1), sum_non_zero(m + 1), ans;
        int pow10[100'001];

        for (int i = 0; i < m; ++i) {
            int d = s[i] - '0';

            new_n[i + 1] = d > 0 ? (new_n[i] * 10LL + d) % MOD : new_n[i];
            sum_d[i + 1] = sum_d[i] + d;
            sum_non_zero[i + 1] = sum_non_zero[i] + (d > 0);
        }
        pow10[0] = 1;
        for (int i = 0; i < 100'000; ++i)
            pow10[i + 1] = pow10[i] * 10LL % MOD;

        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0], r = q[1] + 1;
            int len = sum_non_zero[r] - sum_non_zero[l];
            long long x = new_n[r] - 1LL * new_n[l] * pow10[len] % MOD + MOD;
            ans.push_back(x * (sum_d[r] - sum_d[l]) % MOD);
        }

        return ans;
    }
};