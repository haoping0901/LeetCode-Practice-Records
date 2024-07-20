class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];

        for (int idx=1; idx<nums.size(); ++idx) {
            // Record whether the sum of the current number and the current 
            // accumulated total is greater than the current number. 
            // If it is, it means the search can start from here. 
            if (nums[idx] + nums[idx-1] > nums[idx])
                nums[idx] = nums[idx] + nums[idx-1];
            ret = max(ret, nums[idx]);
        }
        
        return ret;
    }
};