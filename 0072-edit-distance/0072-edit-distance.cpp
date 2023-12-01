class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> rec(word1.length()+1, vector<int>(word2.length()+1, 0));

        // set default values
        for (int i=1; i<=word1.length(); i++) {
            rec.at(i).at(0) = i;
        }
        for (int i=1; i<=word2.length(); i++) {
            rec.at(0).at(i) = i;
        }

        // LCS-like DP
        for (int i=1; i<=word1.length(); i++) {
            for (int j=1; j<=word2.length(); j++) {
                if (word1.at(i-1) != word2.at(j-1)) {
                    rec.at(i).at(j) = min(rec.at(i-1).at(j-1)+1, \
                                          min(rec.at(i-1).at(j)+1, rec.at(i).at(j-1)+1));
                } else {
                    rec.at(i).at(j) = rec.at(i-1).at(j-1);
                }
            }
        }

        return rec.at(word1.length()).at(word2.length());
    }
};