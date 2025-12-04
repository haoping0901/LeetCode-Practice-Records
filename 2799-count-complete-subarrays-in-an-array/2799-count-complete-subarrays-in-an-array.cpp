class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        // Input: 正整數 arr
        // Target: 找到 distinct element 數與整個 array 相同的 subarray 總數
        unordered_set<int> distinct_rec;
        unordered_map<int, int> rec;
        int target;
        int l = 0, r, n = nums.size();
        int ret = 0;

        for (const int& num: nums)
            distinct_rec.insert(num);
        target = distinct_rec.size();

        // Sliding window
        // window 滿足條件時，ret += n - r，並不斷 ++l 然後重複檢查是否滿足條件
        for (r = 0; r < n; ++r) {
            ++rec[nums[r]];

            while (rec.size() == target) {
                ret += n - r;
                --rec[nums[l]];
                if (rec[nums[l]] == 0)
                    rec.erase(nums[l]);
                ++l;
            }
        }

        return ret;
    }
};