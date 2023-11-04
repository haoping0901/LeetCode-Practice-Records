class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int nums_len = nums.size();
        vector<int> answer(nums_len, 1);
        
        // Obtain the left product
        for (int i=1; i<nums_len; i++) {
            answer[i] = answer[i-1] * nums[i-1];
        }

        // Obtain the right product
        int right=1;
        for (int i=nums_len-1; i>=0; i--) {
            answer[i] *= right;
            right *= nums[i];
        }

        return answer;
    }
};