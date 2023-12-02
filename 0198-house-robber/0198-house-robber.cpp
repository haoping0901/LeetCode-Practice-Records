class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        int r0=nums[0], r1, r2;
        r1 = (nums[1] < nums[0]) ? nums[0] : nums[1];
        r2 = r1;

        for (int i=2; i<nums.size(); i++) {
            if (r0+nums[i] < r1) {
                r2 = r1;
            } else {
                r2 = r0 + nums[i];
            }

            r0 = r1;
            r1 = r2;
        }

        return r2;
    }
};