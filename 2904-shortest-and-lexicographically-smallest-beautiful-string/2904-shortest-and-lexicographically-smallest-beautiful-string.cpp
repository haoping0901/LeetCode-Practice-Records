class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l = 0, r;
        int cnt = 0;
        int ret_l = -1, ret_r = -1;

        for (r = 0; r < s.length(); ++r) {
            if (s[r] == '1')
                ++cnt;
            
            if (cnt > k) {
                while (l < r && s[l] != '1')
                    ++l;
                ++l;
                --cnt;
            }

            if (cnt == k) {
                // skip leading 0
                while (l < r && s[l] == '0')
                    ++l;

                if (ret_l == -1) {
                    ret_l = l;
                    ret_r = r;
                } else {
                    if (ret_r - ret_l + 1 > r - l + 1) {
                        ret_l = l;
                        ret_r = r;
                    } else if (ret_r - ret_l + 1 == r - l + 1) {
                        if (s.substr(ret_l, ret_r - ret_l + 1) > s.substr(l, r - l + 1)) {
                            ret_l = l;
                            ret_r = r;
                        }
                    }
                }
            }
        }

        if (ret_r == -1)
            return "";
        else
            return s.substr(ret_l, ret_r - ret_l + 1);
    }
};