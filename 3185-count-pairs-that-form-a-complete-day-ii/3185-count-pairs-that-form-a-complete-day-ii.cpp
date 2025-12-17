class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        // Target: (hi + hj) % 24 == 0, i < j
        vector<int> rec(25, 0);
        long long ret = 0;
        int h_mod;

        for (int h: hours) {
            h_mod = h % 24;

            ret += rec[24 - h_mod];

            if (h_mod == 0)
                ++rec[24];
            else
                ++rec[h_mod];
        }

        return ret;
    }
};