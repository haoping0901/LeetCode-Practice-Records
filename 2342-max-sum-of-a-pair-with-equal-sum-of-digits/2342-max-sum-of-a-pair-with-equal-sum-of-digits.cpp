class Solution {
public:
    int GetSumOfDigits(int n) {
        int ret = 0;
        while (n > 0) {
            ret += n % 10;
            n /= 10;
        }

        return ret;
    }
    int maximumSum(vector<int>& nums) {
        // Input: arr of pos int
        // Target: max n_i + n_j, each digits of n_i == n_j, i != j
        // [14, 5, 311] -> 325
        // map -> rec max num of each sum of digits (sod)
        // Iterate all num, and do following checks:
            // check its sod
            // Check if the sum of max val of sod rec and the val now is bigger than ret
            // if so, than update ret
        unordered_map<int, int> rec;
        int ret = -1;
        int sod;

        for (const auto& n: nums) {
            sod = GetSumOfDigits(n);

            if (rec[sod] == 0) {
                rec[sod] = n;
            } else {
                ret = max(ret, n + rec[sod]);
                rec[sod] = max(rec[sod], n);
            }
        }

        return ret;
    }
};