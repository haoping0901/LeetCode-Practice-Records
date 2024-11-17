class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = 0, ret = -10000;
        for (const int& n: nums) {
            max_sum = max(max_sum + n, 0);
            ret = max_sum == 0 ? max(ret, n) : max(ret, max_sum);
        }

        return ret;
    }
};