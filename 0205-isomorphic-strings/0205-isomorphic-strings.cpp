class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<uint16_t> s_idx(0xff, 0), t_idx(0xff, 0);

        for (int i=0; i<s.length(); i++) {
            if (s_idx[s[i]] != t_idx[t[i]]) 
                return false;
            
            s_idx[s[i]] = i+1;
            t_idx[t[i]] = i+1;
        }

        return true;
    }
};