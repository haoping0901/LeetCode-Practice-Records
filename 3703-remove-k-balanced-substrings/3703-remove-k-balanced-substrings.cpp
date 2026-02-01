class Solution {
public:
    string removeSubstring(string s, int k) {
        vector<pair<char, int>> st;
        string ans;

        for (const char ch : s) {
            if (!st.empty() && st.back().first == ch)
                ++st.back().second;
            else
                st.emplace_back(ch, 1);
            
            if (ch == ')' && st.size() > 1 && st.back().second == k &&
                    st[st.size() - 2].second >= k) {
                st.pop_back();
                st.back().second -= k;
                if (st.back().second == 0)
                    st.pop_back();
            }
        }

        for (const auto& p : st)
            ans += string(p.second, p.first);

        return ans;
    }
};