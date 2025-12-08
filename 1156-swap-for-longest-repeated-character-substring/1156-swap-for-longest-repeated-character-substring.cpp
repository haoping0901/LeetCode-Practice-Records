class Solution {
public:
    int maxRepOpt1(string text) {
        vector<int> rec(26, 0);
        int l, r, n = text.length();
        int swap_n;
        int ret = 0;

        for (char ch: text)
            ++rec[ch - 'a'];

        for (char ch = 'a'; ch <= 'z'; ++ch) {
            swap_n = 0;
            for (l = 0, r = 0; r < n; ++r) {
                swap_n += text[r] != ch;
                while (swap_n > 1) {
                    swap_n -= text[l++] != ch;
                }

                ret = max(ret, min(r - l + 1, rec[ch - 'a']));
            }
        }

        return ret;
    }
};