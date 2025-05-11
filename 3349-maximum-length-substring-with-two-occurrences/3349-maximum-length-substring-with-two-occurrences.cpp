class Solution {
public:
    int maximumLengthSubstring(string s) {
        // 回傳各個字元不重複兩個以上的區間的最大長度
        // 紀錄當前的區間包含哪些字元 => unordered_map
        // 遇到第三個相同字元時，更新區間開始 => beg
            // 還須更新 map
        // 遍歷一次字串
        unsigned max_dist = 0;
        unordered_map<char, unsigned> rec;

        for (size_t i = 0, beg = 0; i < s.length(); ++i) {
            ++rec[s[i]];

            if (rec[s[i]] == 3) {
                while (rec[s[i]] == 3) {
                    --rec[s[beg]];
                    ++beg;
                }
            }

            max_dist = max(max_dist, unsigned(i - beg + 1));
        }

        return max_dist;
    }
};