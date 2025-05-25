class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // sliding window
        // 檢查從兩頭開始的區間加總是否能等於 x
        // 先檢查開頭直到超過 x，或碰到結尾
        // 再檢查左側直到不需要右側區間，或是超過 x

        ssize_t lb;
        ssize_t le;
        unsigned sum = 0;
        int ret = 1000000;

        // left window
        for (lb = 0, le = 0; le < nums.size(); ++le) {
            sum += nums[le];

            if (sum > x) {
                sum -= nums[le];
                le--;
                break;
            }
            
            if (sum == x) {
                ret = min(ret, int(le - lb + 1));
                break;
            }
        }
        if (le == nums.size())
            return ret == 1000000 ? -1 : ret;

        // right side
        for (auto rit_b = nums.rbegin(), rit_e = nums.rbegin(); rit_e != nums.rend(); ++rit_e) {
            sum += *rit_e;

            while (sum > x && le >= lb) {
                sum -= nums[le];
                --le;
            }
            if (sum > x)
                break;

            if (sum == x) {
                ret = min(ret, int((le - lb + 1) + (rit_e - rit_b + 1)));
            }
        }

        return ret == 1000000 ? -1 : ret;
    }
};