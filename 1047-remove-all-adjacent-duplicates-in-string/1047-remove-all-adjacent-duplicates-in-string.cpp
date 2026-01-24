class Solution {
public:
    string removeDuplicates(string s) {
        string ret;

        for (const char c : s) {
            if (!ret.empty() && ret.back() == c)
                ret.pop_back();
            else
                ret.push_back(c);
        }

        return ret;
    }
};