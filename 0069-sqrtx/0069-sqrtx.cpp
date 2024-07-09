class Solution {
public:
    int mySqrt(int x) {
        // case 0 and 1
        if (x < 2) return x;
        int base = 2;

        // First, double the base each time to find the first square 
        // that is greater than x.
        while (static_cast<long long>(base)*base < x) 
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