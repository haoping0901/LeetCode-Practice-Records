class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> rec;
        int n = s.length();
        int target = 1;

        for (int i = 0; i + k <= n; ++i)
            rec.insert(s.substr(i, k));

        for (int i = 0; i < k; ++i)
            target *= 2;

        if (rec.size() != target)
            return false;
        return true;
    }
};