class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int l = 0, r;
        int ret = 0;
        sort(nums.begin(), nums.end());

        for (r = 0; r < nums.size(); ++r) {
            if (nums[r] > nums[l] + (k << 1)) {
                while (nums[l] + (k << 1) < nums[r])
                    ++l;
            }
            ret = max(ret, r - l + 1);
        }

        return ret;
    }
};