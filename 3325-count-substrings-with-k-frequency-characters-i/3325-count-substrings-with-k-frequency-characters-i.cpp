class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        // Sliding window
        // 固定 l，當 r 找到滿足條件的 subarray 時，不斷 ++l 直到不滿足條件
            // ++l 時，如果還滿足條件的話就將 ret += n - r;
        unordered_map<char, int> rec;
        int l = 0, r, n = s.length();
        int ret = 0;

        for (r = 0; r < n; ++r) {
            ++rec[s[r]];

            while (rec[s[r]] >= k) {
                ret += n - r;

                --rec[s[l]];
                ++l;
            }
        }

        return ret;
    }
};