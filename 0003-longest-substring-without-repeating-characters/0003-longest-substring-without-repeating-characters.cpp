class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt=0, max=0, erase_idx=0;
        unordered_map<char, int> rec;

        for (int i=0; i<s.length(); i++) {
            if (rec.count(s.at(i)) > 0) {
                cnt = i-rec.at(s.at(i));
                while (s.at(erase_idx) != s.at(i)) {
                    rec.erase(s.at(erase_idx));
                    erase_idx++;
                }
                if (s.at(erase_idx) == s.at(i)) {
                    rec.erase(s.at(erase_idx));
                    erase_idx++;
                }
                
                rec[s.at(i)] = i;
            } else {
                rec[s.at(i)] = i;
                cnt++;

                if (cnt > max) {
                    max = cnt;
                }
            }
        }

        return max;
    }
};