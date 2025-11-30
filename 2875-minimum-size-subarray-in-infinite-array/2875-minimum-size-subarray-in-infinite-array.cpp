class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        // Sliding window
        // l 需要遍歷過整個 nums
        // 1. 先不斷加總當前 window 的總和，直到超過 k
        // >= k 後
            // > target 就右移 l，直到 <= k
            // == target 時紀錄區間
        int l = 0, r = 0;
        int n = nums.size();
        long long sum = 0, tmp = 0;
        long long ret = -1;
        int complete;

        for (const int& n: nums)
            sum += n;
        complete = n * (target / sum);
        target %= sum;

        while (l < n) {
            tmp += nums[r++ % n];
            while (tmp > target)
                tmp -= nums[l++ % n];

            if (tmp == target) {
                if (ret == -1)
                    ret = r - l + complete;
                else
                    ret = min(ret, (long long)r - l + complete);
            }
        }

        return ret;
    }
};