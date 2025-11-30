class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        // sliding window
        // 紀錄 l ptr 與 r ptr
        // 當滿足 cond. 時不斷右移 r
        // 不滿足時就左移 l，且 reset r = l
        // 重複上方動作直到 l 碰到結尾
        int l = 0, r = 0;
        int n = s.length();
        int cnt0 = 0, cnt1 = 0;
        int ret = 0;

        while (r < n) {
            if (s[r] == '0')
                ++cnt0;
            else
                ++cnt1;
            
            while (cnt0 > k && cnt1 > k) {
                if (s[l++] == '0')
                    --cnt0;
                else
                    --cnt1;
            }

            ret += r - l + 1;
            ++r;
        }

        return ret;
    }
};