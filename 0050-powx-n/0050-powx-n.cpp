class Solution {
public:
    double myPow(double x, int n) {
        long long ln = n;
        if (n < 0) {
            x = 1 / x;
            ln *= -1;
        }

        double ret = 1;

        while (ln) {
            if (ln & 0x1) ret *= x;

            x *= x;
            ln >>= 1;
        }

        return ret;
    }
};