class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> pre(text2.length()+1, 0);
        vector<int> cur(text2.length()+1, 0);

        for (int i=0; i<text1.length(); i++) {
            for (int j=0; j<text2.length(); j++) {
                if (text1.at(i) == text2.at(j)) {
                    cur.at(j+1) = pre.at(j)+1;
                } else {
                    cur.at(j+1) = max(cur.at(j), pre.at(j+1));
                }
            }
            vector<int> tmp=pre;
            pre = cur;
            cur = tmp;
        }

        return pre.back();
    }
};