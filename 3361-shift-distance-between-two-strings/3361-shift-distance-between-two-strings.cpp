class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        // Op.:
            // s[i] == s[i] + 1 - 'a', if s[i] == 'z', s[i] = 'a'
            // s[i] == s[i] - 1, if s[i] == 'a', s[i] = 'z'
            // this op. takes nC[j] cost, j = s[i] - 'a'
        // Target: min cost when transfroming s to t
        // prefix & suffix sum
        vector<long long> pre(26), suf(26);
        long long ans = 0;

        // rec. the prefix / suffix sum from transforming 'a' to 'z' / 'z' to 'a'
        pre[0] = nextCost[25];
        suf[25] = previousCost[0];
        for (int i = 1; i < 26; ++i) {
            pre[i] = pre[i - 1] + nextCost[i - 1];
            suf[25 - i] = suf[26 - i] + previousCost[26 - i];
        }

        // for each char. of s
        for (int i = 0; i < s.length(); ++i) {
            // rec. the min(prefix, suffix) to the ans.
            long long next_sum = 0, prev_sum = 0;

            if (s[i] < t[i]) { // s[i] == 'a', t[i] == 'c'
                next_sum = pre[t[i] - 'a'] - pre[s[i] - 'a'];

                prev_sum = suf[0] - suf[s[i] - 'a'];
                prev_sum += suf[t[i] - 'a'];
            } else if (s[i] > t[i]) { // s[i] == 'c', t[i] == 'a'
                next_sum = pre[25] - pre[s[i] - 'a'];
                next_sum += pre[t[i] - 'a'];

                prev_sum = suf[t[i] - 'a'] - suf[s[i] - 'a'];
            }

            ans += min(next_sum, prev_sum);
        }

        return ans;
    }
};
// Input
// s    abc
// t:   zab
// nC:  [1, 2, 3, .. , 26]
// pC:  [26, 25, 24, .. , 1]
// a -> z:
    // nC['a' - 'a' == 0] + .. + nC['y' - 'a']
    // pC['a' - 'a']
