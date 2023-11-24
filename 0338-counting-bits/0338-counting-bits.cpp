class Solution {
public:
    vector<int> countBits(int n) {
        vector ret(n+1, 0);

        for (int i=1; i<n+1; i++) {
            ret.at(i) = ret.at(i>>1) + (i & 1);
        }

        return ret;
    }
};