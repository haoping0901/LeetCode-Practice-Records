class Solution {
public:
    int maximumCount(vector<int>& nums) {
        // Target: Return max(num of pos int, num of neg int)
        // Input: nums in <= order

        // Binary search first 0 and first non-zero
        int l, r, m;
        int ret = 0;

        // Binary search first 0
        l = 0;
        r = nums.size() - 1;
        while (l <= r) {    // close interval
            m = l + ((r - l) >> 1);
            if (nums[m] >= 0)
                r = m - 1;
            else
                l = m + 1;
        }
        ret = l;

        // Binary search first > 0
        r = nums.size() - 1;
        while (l <= r) {
            m = l + ((r - l) >> 1);
            if (nums[m] > 0)
                r = m - 1;
            else
                l = m + 1;
        }
        ret = max(ret, (int)nums.size() - l);

        return ret;
    }
};