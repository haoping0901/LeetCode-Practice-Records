class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (!left || !right) return 0;
        if (left == right) return left;
        int ret, lth = log2(left), rth = log2(right);
        
        // get the position of leading bit 1 in both left and right
        // left: lth, right: rth
        // only look up [lth, right)]
        if (lth == rth) {
            ret = left;
            for (long i=left+1; i<=right; i++) ret &= i;
        } else 
            ret = 0;

        return ret;
    }
};