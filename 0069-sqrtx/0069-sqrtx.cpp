class Solution {
public:
    int mySqrt(int x) {
        int base = 2;

        // 先讓 base 每次成長兩倍去找到第一個平方後比 x 大的數字
        while(static_cast<long long>(base)*base < x) 
            base <<= 1;
        

        // binary search
        if (static_cast<long long>(base)*base == x) return base;
        int l = base >> 1, r = base, m = r + ((l-r) >> 1);

        while (l < r) {
            if (static_cast<long long>(m)*m < x)
                l = m + 1;
            else
                r = m;
            
            m = r + ((l-r) >> 1);
        }

        return static_cast<long long>(m)*m == x ? m : m - 1;
    }
};