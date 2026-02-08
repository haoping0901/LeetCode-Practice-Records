class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> index(n);
        stack<int> st;
        string ans;
        int idx = 0, step = 1;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top();
                st.pop();
                index[i] = j;
                index[j] = i;
            }
        }

        while (idx < n) {
            if (s[idx] == '(' || s[idx] == ')') {
                idx = index[idx];
                step = -step;
            } else {
                ans.push_back(s[idx]);
            }

            idx += step;
        }

        return ans;
    }
};