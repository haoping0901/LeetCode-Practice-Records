class Solution {
public:
    int Reverse(int n) {
        int ret = 0;

        while (n > 0) {
            ret = ret * 10 + n % 10;
            n /= 10;
        }

        return ret;
    }

    int countNicePairs(vector<int>& nums) {
        // Input: vec of num (>= 0)
        // Target: number of nice pairs (% 1e9 + 7)
            // nice: ni + rev(nj) == nj + rev(ni), i < j
            // nj - rev(nj) == ni - rev(ni)
        // {ni - rev(ni), cnt}
        unordered_map<int, int> rec;
        long long ret = 0;
        int nice_val;

        for (const int& n: nums) {
            nice_val = n - Reverse(n);
            ret = (ret + rec[nice_val]) % 1000000007;
            ++rec[nice_val];
        }

        return (int)ret;
    }
};