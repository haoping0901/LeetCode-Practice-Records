class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() > t.length())
            return false;

        int tidx, sidx;
        for (tidx=0, sidx=0; tidx<t.length() && sidx<s.length(); tidx++) {
            if (s.at(sidx) == t.at(tidx)) {
                sidx++;
            }
        }

        if (sidx == s.length())
            return true;
        else
            return false;
    }
};