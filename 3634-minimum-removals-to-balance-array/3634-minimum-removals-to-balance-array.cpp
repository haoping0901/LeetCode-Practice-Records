class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        int max_size = 0;
        int l = 0;
        sort(nums.begin(), nums.end());

        for (int r = 0; r < n; ++r) {
            while (nums[r] > (long long) nums[l] * k)
                ++l;
            max_size = max(max_size, r - l + 1);
        }

        return n - max_size;
    }
};