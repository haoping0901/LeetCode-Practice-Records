class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // {sum % k, counter} rec number of sum after mod. k
        unordered_map<int, int> rec;
        int ans = 0, sum = 0;

        for (const int n : nums) {
            ++rec[sum];
            sum = (sum + n % k + k) % k;
            ans += rec[sum];
        }

        return ans;
    }
};
// Input: [1, 5, 14, 10], k = 5
// Output: 4 ([5], [10], [1, 5, 14], [1, 5, 14, 10])