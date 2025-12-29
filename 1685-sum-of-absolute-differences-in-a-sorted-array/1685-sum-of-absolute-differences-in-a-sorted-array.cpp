class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        // Target: build an array r that r[i] == abs(n[i] - n[j]), j < n, j != i
        int n = nums.size();
        vector<int> prefix(n + 1);

        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + nums[i];
        
        for (int i = 0; i < n; ++i)
            nums[i] = (nums[i] * i - prefix[i]) +
                      (prefix[n] - prefix[i + 1] - nums[i] * (n - 1 - i));
        
        return nums;
    }
};
// Input: [1, 2, 3, 4]
// Output: [1 + 2 + 3 = 6, 1 + 1 + 2 = 4, 2 + 1 + 1 = 4, 3 + 2 + 1= 6]
// prefix sum: [0, 1, 3, 6, 10]