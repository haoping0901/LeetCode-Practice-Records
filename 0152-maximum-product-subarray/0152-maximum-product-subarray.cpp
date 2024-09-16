class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = -16, cur_product = 1;
        for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
            cur_product *= *iter;
            ans = max(ans, cur_product);
            if (*iter == 0)
                cur_product = 1;
        }
        cur_product = 1;
        for (auto iter = nums.rbegin(); iter != nums.rend(); ++iter) {
            cur_product *= *iter;
            ans = max(ans, cur_product);
            if (*iter == 0)
                cur_product = 1;
        }

        return ans;
    }
};