class Solution {
public:
    int subarraySum(vector<int>& nums) {
        // subarray: nums[max(0, i - nums[i]) .. i]
            // [2, 3, 1]
            // i = 0: nums[max(0, 0 - 2) .. 0] => nums[0 .. 0] = 2
            // i = 1: nums[max(0, 1 - 3) = 0 .. 1] => 2 + 3 = 5
            // i = 2: nums[max(0, 2 - nums[2]) = 1 .. 2] => 3 + 1 = 4
        // Target: total sum of all elements of all subarray
        // prefix sum: an array (rec) store the cumulative sum of nums from
        // the 1st element
        // For each subarray, take the diff. of last element and first element
        int n = nums.size(), ans = 0;
        vector<int> rec(n + 1);

        for (int i = 1; i <= n; ++i)
            rec[i] = rec[i - 1] + nums[i - 1];

        for (int i = 0; i < n; ++i) {
            int start, end;

            start = max(0, i - nums[i]);
            end = i + 1;
            
            // start = i - n (n > 1), end = i => end > start
            ans += rec[end] - rec[start];
        }

        return ans;
    }
};