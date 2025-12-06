class Solution {
public:
    int Solve(vector<int>& nums, int k) {
        int l = 0, r, cnt = 0;
        int ret = 0;

        for (r = 0; r < nums.size(); ++r) {
            if ((nums[r] & 0x1) == 0x1)
                ++cnt;

            while (cnt > k) {
                if ((nums[l++] & 0x1) == 0x1)
                    --cnt;
            }

            ret += r - l + 1;
        }

        return ret;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        // k nice -> sub arr with at most k - 1 nice - 
        // sub arr with at most k nice
        // 10 + 4 - 6 - 3  - 3
        // 55 - 21 - 18
        return Solve(nums, k) - Solve(nums, k - 1);
    }
};