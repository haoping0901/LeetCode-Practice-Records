class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;

        make_heap(nums.begin(), nums.end());

        while (k-- > 0) {
            pop_heap(nums.begin(), nums.end());
            score += nums.back();
            nums.back() = (nums.back() + 2) / 3;
            push_heap(nums.begin(), nums.end());
        }

        return score;
    }
};