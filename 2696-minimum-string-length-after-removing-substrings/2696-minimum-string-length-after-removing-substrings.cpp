class Solution {
public:
    int minLength(string s) {
        // Iterate s, for each char s[i]:
            // if (s[i] == 'B" && st.top() == 'A' || s[i] == 'D' && st.top() == 'D')
                // pop st.top
            // else: push s[i] into a stack st
        // return st.size()
        stack<char> st;

        for (const char c : s) {
            if (c == 'B' && !st.empty() && st.top() == 'A')
                st.pop();
            else if (c == 'D' && !st.empty() && st.top() == 'C')
                st.pop();
            else
                st.push(c);
        }

        return st.size();
    }
};