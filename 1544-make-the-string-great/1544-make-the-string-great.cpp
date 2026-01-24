class Solution {
public:
    string makeGood(string s) {
        // good str: str exluding upper_case(s[i]) != s[i + 1], i <= s.length() - 2
        string ans;

        auto check_adj = [](const char c1, const char c2) -> bool {
            return ((c1 - 'a' == c2 - 'A') || (c1 - 'A' == c2 - 'a'));
        };

        for (const char c : s) {
            if (!ans.empty() && check_adj(ans.back(), c))
                ans.pop_back();
            else
                ans.push_back(c);
        }

        return ans;
    }
};