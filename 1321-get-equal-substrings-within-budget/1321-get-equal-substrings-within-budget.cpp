class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        // 在特定區間內用 maxCost 以內的開銷替換字元的最大長度
        unsigned ret = 0;
        // 紀錄區間起點
        // 當前剩餘的籌碼
        int chip = maxCost;
        
        for (size_t beg = 0, end = 0; end < s.length(); ++end) {
            chip -= abs(s[end] - t[end]);

            while (chip < 0) {
                chip += abs(s[beg] - t[beg]);

                ++beg;
            }

            ret = max(ret, unsigned(end - beg + 1));
        }

        return ret;
    }
};