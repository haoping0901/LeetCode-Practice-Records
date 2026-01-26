class Solution {
public:
    int minDeletion(vector<int>& nums) {
        // beautiful: 
            // (nums.length() & 0x1) == 0
            // num[i] != nums[i + 1], (i & 0x1) == 0
        int n = nums.size(), ans = 0;

        for (int i = 0; i < n - 1; ++i) {
            if (((i - ans) & 0x1) == 0 && nums[i] == nums[i + 1])
                ++ans;
        }

        return ((n - ans) & 0x1) == 0 ? ans : ans + 1;
    }
};