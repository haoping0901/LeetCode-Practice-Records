class Solution {
public:
    double myPow(double x, int n) {
        bool is_negative = false;
        long long ln = n;
        if (n < 0) {
            is_negative = true;
            ln *= -1;
        }

        int max_exp = 0;
        double ret = 1;
        // 紀錄 x 在次方數為 2 的次方時的值
        vector<double> exp_table(32, 0);
        exp_table[0] = x;

        for (auto cpy_n = ln; cpy_n > 1; cpy_n >>= 1, ++max_exp) {
            // n =      10
            // cpy_n:   10, 5, 2, 1
            // idx:     0,  1, 2, 3
            exp_table[max_exp+1] = exp_table[max_exp] * exp_table[max_exp];
        }

        while (ln) {
            if (ln - (1LL << max_exp) >= 0) {
                ret *= exp_table[max_exp];
                ln -= 1LL << max_exp;
            }
            
            --max_exp;
        }

        return is_negative ? 1 / ret : ret;
    }
};