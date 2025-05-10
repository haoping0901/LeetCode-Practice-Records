class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // sliding window
        // 找到長度為 k     => 累計 k 個數才檢查目前的 sum 是否為最大值
        // 所有數字不重複   => set check 看過哪些數
        // 最大的總和       => max_sum
        unordered_set<int> rec;
        size_t l;
        size_t r;
        long long sum = 0;
        long long ret = 0;

        for (l = 0, r = 0; r < nums.size(); ++r) {
            if (rec.find(nums[r]) == rec.end()) {
                rec.insert(nums[r]);
                sum += nums[r];
            } else {
                while (nums[l] != nums[r]) {
                    rec.erase(nums[l]);
                    sum -= nums[l];
                    ++l;
                }
                ++l;
            }

            if (rec.size() == k) {
                ret = max(ret, sum);

                rec.erase(nums[l]);
                sum -= nums[l];

                ++l;
            }
        }

        return ret;
    }
};