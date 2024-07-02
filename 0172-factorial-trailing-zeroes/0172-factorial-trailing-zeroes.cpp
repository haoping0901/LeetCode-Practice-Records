class Solution {
public:
    int trailingZeroes(int n) {
        int two_cnt = 0, five_cnt = 0;

        // 將每階層增加的數字因式分解後紀錄 2 與 5 的數量
        // 累計後取兩者最小值回傳
        while (n > 0) {
            int tmp = n;

            while (!(tmp&0x1)) {
                tmp >>= 1;
                ++two_cnt;
            }
            
            while (tmp%5 == 0) {
                tmp /= 5;
                ++five_cnt;
            }

            --n;
        }

        return min(two_cnt, five_cnt);
    }
};