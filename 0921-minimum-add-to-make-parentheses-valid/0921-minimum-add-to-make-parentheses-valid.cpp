class Solution {
public:
    int minAddToMakeValid(string s) {
        // Target: steps to make s[i] are all paired
        // Iterate the s, for each s[i]
            // '(':
                // ++cnt_l
            // ')':
                // cnt_l > 0 => --cnt_l
                // ++unmatch_rp
        // ans == cnt_l + unmatch_rp
        int cnt_l = 0, unmatch_rp = 0;

        for (const char ch : s) {
            if (ch == ')') {
                if (cnt_l > 0)
                    --cnt_l;
                else
                    ++unmatch_rp;
            } else { // '('
                ++cnt_l;
            }
        }

        return cnt_l + unmatch_rp;
    }
};