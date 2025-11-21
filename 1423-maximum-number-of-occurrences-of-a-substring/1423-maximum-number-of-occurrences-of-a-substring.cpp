class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int l, r;
        int len = s.length();
        int ret = 0;
        unordered_map<string, int> rec;

        // sliding window
        for (l = 0; l + minSize <= len; ++l) {
            r = l + minSize;
            string tmp(s.begin() + l, s.begin() + r);
            unordered_set<char> ch_rec(tmp.begin(), tmp.end());

            if (ch_rec.size() > maxLetters)
                continue;

            ret = max(ret, ++rec[tmp]);
        }

        return ret;
    }
};