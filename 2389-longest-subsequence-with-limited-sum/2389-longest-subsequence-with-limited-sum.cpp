class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        // Target: return ans vector, an == max(j - i + 1), j >= i, s[j + 1] - s[i] <= qn
        // {prefix sum, first appeared}
        // Brute force
        // m * n^2
        // prefix w. binary search: m * nlogn
        ranges::sort(nums);
        for (int i = 1; i < nums.size(); ++i)
            nums[i] += nums[i - 1];
        
        for (int& q : queries)
            q = ranges::upper_bound(nums, q) - nums.begin();

        return queries;
    }
};
// Input:
// nums:    [1, 2, 3, 4]
// queries: [4, 8, 16]
// Output:  [2, 3, 4]
// prefix sum: [1, 3, 6, 10]