class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        unsigned cnt = 0;

        for (const int& n: arr) {
            if (n & 0x1) {
                ++cnt;

                if (cnt == 3)
                    return true;
            } else {
                cnt = 0;
            }
        }

        return false;
    }
};