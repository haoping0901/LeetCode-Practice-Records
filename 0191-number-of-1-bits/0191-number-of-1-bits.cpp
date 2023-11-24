class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;

        while (n > 0) {
            if (1 & n) {
                cnt++;
            }
            n >>= 1;
        }

        return cnt;
    }
};