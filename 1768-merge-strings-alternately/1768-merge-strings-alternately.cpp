class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int idx1, idx2, len1=word1.length(), len2=word2.length();
        string ret;

        for (idx1=0, idx2=0; idx1<len1 && idx2 < len2; idx1++, idx2++) {
            ret.push_back(word1.at(idx1));
            ret.push_back(word2.at(idx2));
        }

        ret.append(word1.begin()+idx1, word1.end());
        ret.append(word2.begin()+idx2, word2.end());

        return ret;
    }
};