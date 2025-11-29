class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> rec;
        int n = s.length();
        int target = n >> 2;
        int ret = n;

        for (const auto& c: s)
            ++rec[c];
        
        if (rec['Q'] == target && rec['W'] == target &&
                rec['E'] == target && rec['R'] == target)
            return 0;

        for (int l = 0, r = 0; r < n; ++r) {
            --rec[s[r]];

            while (l <= r && rec['Q'] <= target && rec['W'] <= target &&
                   rec['E'] <= target && rec['R'] <= target) {
                ret = min(ret, r - l + 1);
                ++rec[s[l]];
                ++l;
            }
        }

        return ret;
    }
};