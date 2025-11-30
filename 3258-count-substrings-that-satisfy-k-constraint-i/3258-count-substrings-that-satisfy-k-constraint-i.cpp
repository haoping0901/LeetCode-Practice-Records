class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        // sliding window
        // 紀錄 l ptr 與 r ptr
        // 當滿足 cond. 時不斷右移 r
        // 不滿足時就左移 l，且 reset r = l
        // 重複上方動作直到 l 碰到結尾
        int l = 0, r;
        int n = s.length();
        int cnt0, cnt1;
        int ret = 0;

        for (l = 0; l < n; ++l) {
            cnt0 = cnt1 = 0;
            for (r = l; r < n; ++r) {
                if (s[r] == '1')
                    ++cnt1;
                else
                    ++cnt0;
                
                if (cnt1 > k && cnt0 > k)
                    break;
                
                ++ret;
            }
        }

        return ret;
    }
};