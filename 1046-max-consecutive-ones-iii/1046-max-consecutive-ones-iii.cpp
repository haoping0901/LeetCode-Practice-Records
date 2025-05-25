class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // sliding window
        size_t begin;
        size_t end;
        int ret = 0;

        // 每次新加入一個數字後，檢查從該數字往前看的最長連續 1 的區間是否是最大值
        for (begin = 0, end = 0; end < nums.size(); ++end) {
            if (nums[end] == 0) {
                if (k > 0) {
                    --k;
                } else {
                    // 歸還一個 0 轉成 1 的額度
                    while (nums[begin] != 0)
                        ++begin;
                    ++begin;
                }
            }
            ret = max(ret, int(end - begin + 1));
        }

        return ret;
    }
};