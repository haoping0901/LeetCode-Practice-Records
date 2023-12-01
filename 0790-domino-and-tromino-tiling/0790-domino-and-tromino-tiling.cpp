class Solution {
public:
    int numTilings(int n) {
        if (n < 3)
            return n;

        // f_cur = f_cur + f_pre + par
        // par = par + f_pre
        long mod=1e9+7, f_cur=2, f_pre=1, par=1;

        for (int i=3; i<=n; i++) {
            long tmp = f_cur;
            f_cur = (f_cur + f_pre + par*2) % mod;
            par = (par + f_pre) % mod;
            f_pre = tmp;
        }

        return (int) f_cur;
    }
};