class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<uint32_t> rec(26, 0);

        for (const char ch: magazine) 
            rec[ch-'a']++;

        for (const char ch: ransomNote) {
            if (rec[ch-'a'] == 0)
                return false;
            else 
                rec[ch-'a']--;
        }

        return true;
    }
};