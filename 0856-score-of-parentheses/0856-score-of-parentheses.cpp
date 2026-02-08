class Solution {
public:
    int scoreOfParentheses(string s) {
        // Go through s, for each s[i]
            // '(':
                // if score != 0, then push it into stack st 
                // push -1 into st
            // ')': check if there exist score between topmost '('
                // if so, then double that score
                // otherwise, score = 1
                // then, push back the score into st if st.top == 0, other st.top += score
        stack<int> st; // 0 for '('
        int ans = 0, score = 0;

        for (const char ch : s) {
            if (ch == '(') {
                if (score > 0) {
                    st.push(score);
                    score = 0;
                }

                st.push(0);
            } else { // ch == ')'
                if (st.top() != 0) {
                    score = st.top() * 2;
                    st.pop();
                } else {
                    score = 1;
                }
                st.pop();

                if (st.empty()) // "()"
                    ans += score;
                else if (st.top() == 0) // "(())"
                    st.push(score);
                else if (st.top() > 0) // "(()())"
                    st.top() += score;

                score = 0;
            }
        }

        return ans;
    }
};
// Input:   "((()))"
// Output:  4