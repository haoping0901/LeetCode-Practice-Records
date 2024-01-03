class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == right) return left;
        int ret, lth = 0, rth = 0;
        
        // get the position of leading bit 1 in both left and right
        // left: lth, right: rth
        // only look up [lth, min(l+1th-1, right)]
        
        for (int i=0; i<32; i++) {
            if ((left>>i) & 1) lth = i;
            if ((right>>i) & 1) rth = i;
        }

        if (lth == rth) {
            ret = left;
            for (long i=left+1; i<=right; i++) ret &= i;
        } else 
            ret = 0;

        return ret;
    }
};