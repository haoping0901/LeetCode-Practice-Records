class Solution {
public:
    int ReverseNum(int n) {
        int ret = 0;

        while (n > 0) {
            ret = ret * 10 + n % 10;
            n /= 10;
        }

        return ret;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        // Input: arr of num
        // Target: min size of window that contains mirror pair
            // mirror pair: reverse(n_i) == n_j, j > i
                // reverse(): revert digit of n, leading 0 is omitted
        // {reverse num, max idx}
        unordered_map<int, int> rec;
        int ret = nums.size();
        int i, rvt;

        for (i = 0; i < nums.size(); ++i) {
            if (rec[nums[i]] > 0)
                ret = min(ret, i + 1 - rec[nums[i]]);

            rvt = ReverseNum(nums[i]);
            rec[rvt] = i + 1;
        }

        return ret == nums.size() ? -1 : ret;
    }
};