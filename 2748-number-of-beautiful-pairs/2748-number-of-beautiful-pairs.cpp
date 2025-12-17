class Solution {
    // 0 for gcd for 1, bit is 1 when it's coprime to (idx + 1)
    vector<int> gcd_tab_;
public:
    void InitGCDTable() {
        int i, j;

        gcd_tab_ = vector<int>(9);

        for (i = 1; i <= 9; ++i) {
            for (j = i; j <= 9; ++j) {
                if (GCD(i, j) == 1) {
                    gcd_tab_[i - 1] |= (1 << j);
                    gcd_tab_[j - 1] |= (1 << i);
                }
            }
        }
    }

    int GCD(int a, int b) {
        int tmp;

        while (b > 0) {
            tmp = b;
            b = a % b;
            a = tmp;
        }

        return a;
    }

    int GetLSB(int n) {
        return n % 10;
    }

    int GetMSB(int n) {
        while (n >= 10)
            n /= 10;

        return n;
    }

    bool IsCoprime(int a, int b) {
        return (gcd_tab_[a - 1] >> b) & 0x1;
    }

    int countBeautifulPairs(vector<int>& nums) {
        // Target: amount of beautiful pair
            // beautiful pair: MS bit of ni (Mi) and LS bit of nj (Lj) are coprime, i < j
            // Mi's range: [1, 9]
            // Lj's range: [1, 9]
        // For each num, rec its MSB to rec, 
        // and add all other known gcd pair (rec in other var) to ret
            // rec: {MSB, cnt}
        vector<int> rec(9, 0);
        int ret = 0;
        int Mi, Li;
        int i;
        
        InitGCDTable();
        for (int n: nums) {
            Li = GetLSB(n);

            for (i = 1; i <= 9; ++i) {
                if (IsCoprime(Li, i) == true)
                    ret += rec[i - 1];
            }
            
            Mi = GetMSB(n);
            ++rec[Mi - 1];
        }

        return ret;
    }
};