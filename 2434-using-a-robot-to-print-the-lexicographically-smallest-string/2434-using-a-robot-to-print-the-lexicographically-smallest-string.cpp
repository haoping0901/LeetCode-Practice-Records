class Solution {
public:
    string robotWithString(string s) {
        // Input: empty str s
        // Target: s & t are both empty after applying the following steps:
            // move s[0] to t[n] (push)
            // move t[n] - 1 to return str ret (pop)
            // pop the min_lex(s[i], t[n]), i < s.length()
                // if pop s[i], push s[j] to t, j < i,
        int n = s.length();
        vector<char> suf_min(n + 1);
        stack<char> st;
        string ret;

        suf_min[n] = 'z';
        for (int i = n - 1; i >= 0; --i)
            suf_min[i] = min(suf_min[i + 1], s[i]);
        
        for (int i = 0; i < n; ++i) {
            st.push(s[i]);

            while (!st.empty() && st.top() <= suf_min[i + 1]) {
                ret.push_back(st.top());
                st.pop();
            }
        }

        return ret;
    }
};