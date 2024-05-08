class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int last_idx = nums.size()-1, l = 0, r = last_idx;
        vector<int> ret(2, -1);
        if (last_idx < 0 || nums[0] > target || nums[last_idx] < target)
            return ret;

        while (l <= r) {
            int m = l + ((r-l) >> 1);

            if (nums[m] < target) 
                l = m + 1;
            else
                r = m - 1;
        }
        ret[0] = (nums[l] == target) ? l : -1;
        r = last_idx;

        while (l <= r) {
            int m = l + ((r-l) >> 1);

            if (nums[m] <= target) 
                l = m + 1;
            else
                r = m - 1;
        }

        ret[1] = (nums[l-1] == target) ? l-1 : -1;

        return ret;
    }
};