class Solution {
public:
    int minSwaps(string s) {
        // Target: min swaps to make s balance
            // not paired '[' or ']' -> all ']' before '[' after removing balanced string
        
        
        // Iterate s, for each s[i]:
            // '[': use cnt_r  to count number of '['
            // ']':
                // cnt_r > 0: --cnt_r
                // ++unpaired_l
        int cnt_r = 0, unpaired_l = 0;

        for (const char ch : s) {
            if (ch == ']') {
                if (cnt_r > 0)
                    --cnt_r;
                else
                    ++unpaired_l;
            } else if (ch == '[') {
                ++cnt_r;
            }
        }

        return (unpaired_l + 1) >> 1;
    }
};