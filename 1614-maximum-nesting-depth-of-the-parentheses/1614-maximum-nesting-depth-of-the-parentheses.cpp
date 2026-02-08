class Solution {
public:
    int maxDepth(string s) {
        // Go through s,
            // push each '(' into a stack st (int st++), and record max(ans, st)
            // pop stack when encountering ')'
            // discard other of character
        int st = 0, ans = 0;

        for (const char ch : s) {
            if (ch == '(') {
                ++st;
                ans = max(ans, st);
            } else if (ch == ')') {
                --st;
            }
        }

        return ans;
    }
};