class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        // Sliding window
        // 擴大 window 時，檢查是否與原邊界相同
            // 是: 判斷是否已經有 same digit pair
                // 有一個變數紀錄 same digit
                // 有: 縮小邊界直到遇到 same digit
            // 不是: 紀錄 same digit 即可
        int l = 0, r = 0;
        int same_digit = -1; // -1 for no same digit
        int ret = 1;

        while (r + 1 < s.length()) {
            if (s[r + 1] == s[r]) {
                if (same_digit != -1) {
                    while (s[l] != s[l + 1])
                        ++l;
                    ++l;
                }
                same_digit = s[r];
            }

            ++r;
            ret = max(ret, r - l + 1);
        }

        return ret;
    }
};