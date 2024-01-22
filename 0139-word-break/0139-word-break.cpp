class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> rec(s.length(), false);

        for (int i=0; i<s.length(); i++) {
            for (const string& word: wordDict) {
                if (i < word.length()-1) continue;

                // check whether the word is equal to the start of the string s, 
                // or whether the word is equal to the string start from last equal place
                if (i == word.length()-1 || rec[i-word.length()]) {
                    if (s.substr(i-word.length()+1, word.length()) == word) {
                        rec[i] = true;
                        break;
                    }
                }
            }
        }

        return rec[s.length()-1];
    }
};