class Solution {
public:
    string reverseParentheses(string s) {
        // string ans: rec part of string to be returned
        // stack<string> st: rec part of string needed to be reversed
        // Go through s, for each s[i]
            // s[i] == '(': push string handling now tmp into stack if !tmp.empty()
            // s[i] == ')': reverse tmp and concatenate to st.top() if !st.empty()
                // otherwise, concatenate to ans
            // s[i] == lower case letter
                // tmp.push_back(s[i])
        stack<string> st;
        string ans, tmp;

        for (const char ch : s) {
            if (ch == '(') {
                if (!tmp.empty()) {
                    st.push(tmp);
                    tmp.clear();
                }

                st.push("(");
            } else if (ch == ')') {
                reverse(tmp.begin(), tmp.end());
                st.pop();

                if (!st.empty() && st.top() != "(") {
                    st.top() += tmp;
                    tmp = st.top();
                    st.pop();
                } else if (st.empty()) {
                    ans += tmp;
                    tmp.clear();
                }
            } else { // ch == lower case English letters
                tmp.push_back(ch);
            }
        }

        return ans + tmp;
    }
};
// Input:   "ab(cd(e))"
// Output:  "abedc"