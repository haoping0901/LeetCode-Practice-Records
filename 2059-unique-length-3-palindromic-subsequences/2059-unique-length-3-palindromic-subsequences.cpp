class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // key point: find out the number of unique characters within the 
        // largest interval between two identical characters
        // so we need the following two information:
            // the largest interval between two identical characters
            // the number of unique characters within this interval
        int ret = 0;
        vector<int> first(26, s.length()), last(26, 0);
        for (int idx=0; idx<s.length(); ++idx) {
            int rec_idx = s[idx] - 'a';
            first[rec_idx] = min(first[rec_idx], idx);
            last[rec_idx] = idx;
        }

        for (int idx=0; idx<26; ++idx) {
            if (first[idx] < last[idx]) {
                ret += unordered_set<char>(s.begin() + first[idx] + 1, 
                                           s.begin() + last[idx]).size();
            }
        }
        return ret;
    }
};