class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int nums_len = nums.size();
        int rotate_num = k % nums_len;
        std::rotate(nums.begin(), nums.end()-rotate_num, nums.end());
    }
};