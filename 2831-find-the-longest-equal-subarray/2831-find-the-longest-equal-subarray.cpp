class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> rec;
        int l = 0, r;
        int ret = 0;

        for (r = 0; r < nums.size(); ++r) {
            ++rec[nums[r]];
            ret = max(ret, rec[nums[r]]);

            if (r - l + 1 - ret > k) {
                --rec[nums[l]];
                ++l;
            }
        }

        return ret;
    }
};