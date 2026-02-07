class Solution {
public:
    string removeOuterParentheses(string s) {
        // use a stack to find the outermost parentheses
        // Iterate s, for each s[i]:
            // '(':
                // if stack !st.empty(), push into string ret
                // push into stack st
            // ')': pop st, and check if !st.emtpy
                // if so, push into string ret
        string ret;
        stack <char> st;

        for (const char ch : s) {
            if (ch == '(') {
                if (!st.empty())
                    ret.push_back(ch);
                st.push(ch);
            } else { // ')'
                st.pop();
                if (!st.empty())
                    ret.push_back(ch);
            }
        }

        return ret;
    }
};