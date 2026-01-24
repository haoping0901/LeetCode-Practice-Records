class Solution {
public:
    string resultingString(string s) {
        string ans;

        auto check_consecutive = [](const char c1, const char c2) -> bool {
            return (((c2 - 'a' + 1) % 26 == (c1 - 'a')) ||
                    ((c1 - 'a' + 1) % 26 == (c2 - 'a')));
        };

        for (const char c : s) {
            if (!ans.empty() && check_consecutive(ans.back(), c))
                ans.pop_back();
            else
                ans.push_back(c);
        }

        return ans;
    }
};