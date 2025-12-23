class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = 0, max_sum = 0, min_sum = 0;

        for (const int n : nums) {
            sum += n;

            max_sum = max(max_sum, sum);
            min_sum = min(min_sum, sum);
        }

        return max_sum - min_sum;
    }
};