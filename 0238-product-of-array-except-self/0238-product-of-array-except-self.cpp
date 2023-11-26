class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int tmp_r=1, tmp_l=1;
        vector<int> left_product;
        vector<int> right_product;
        
        for (int i=0, j=nums.size()-1; i<nums.size()-1; i++, j--) {
            tmp_l *= nums.at(i);
            tmp_r *= nums.at(j);
            left_product.push_back(tmp_l);
            right_product.push_back(tmp_r);
        }

        vector<int> ret(nums.size());
        ret.at(0) = right_product.at(right_product.size()-1);
        ret.at(ret.size()-1) = left_product.at(left_product.size()-1);
        
        for (int r=right_product.size()-2, l=0, i=1; i<ret.size()-1; i++, r--, l++) {
            ret.at(i) = right_product.at(r)*left_product.at(l);
        }

        return ret;
    }
};