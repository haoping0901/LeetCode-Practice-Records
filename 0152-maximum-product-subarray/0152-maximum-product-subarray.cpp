class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int nums_len = nums.size(), front_product=1, end_product=1, max;
        int end_idx = nums_len-1;

        for (int i=0; i<nums_len; i++) {
            if (i == 0)
                max = nums[i];
            front_product *= nums[i];
            end_product *= nums[end_idx-i];

            // record the maximum
            if (front_product > max)
                max = front_product;
            if (end_product > max)
                max = end_product;

            // tackle the 0 case
            if (front_product == 0)
                front_product = 1;
            if (end_product == 0)
                end_product = 1;
        }

        return max;
    }
};