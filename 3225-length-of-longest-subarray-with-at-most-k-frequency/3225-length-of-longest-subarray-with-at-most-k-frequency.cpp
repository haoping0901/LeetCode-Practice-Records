class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        // 找到區間中每個數字出現的次數 <= k 的最大長度
        // 紀錄出現次數 => unordered_map
        unordered_map<int, unsigned> rec;
        unsigned ret = 0;

        for (size_t beg = 0, end = 0; end < nums.size(); ++end) {
            ++rec[nums[end]];

            while (rec[nums[end]] > k) {
                --rec[nums[beg]];
                ++beg;
            }

            ret = max(ret, unsigned(end - beg + 1));
        }

        return ret;
    }
};