class Solution {
public:
    bool isAnagram(string s, string t) {
        // count each letter
        vector<int> s_letter_cnt(26, 0), t_letter_cnt(26, 0);

        for (const char ch: s)
            s_letter_cnt[ch-'a']++;
        for (const char ch: t)
            t_letter_cnt[ch-'a']++;

        for (int i=0; i<26; i++)
            if (s_letter_cnt[i] != t_letter_cnt[i])
                return false;

        return true;
    }
};