class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        // Target: return array arr,
        // each element an = abs(i - j), i != j, ai == aj
        unordered_map<int, vector<int>> rec;
        int n = nums.size();
        vector<long long> ans(n), prefix(n + 1);

        for (int i = 0; i < n; ++i)
            rec[nums[i]].push_back(i);
        
        for (auto& [_, vec] : rec) {
            int m = vec.size();

            for (int i = 0; i < m; ++i)
                prefix[i + 1] = prefix[i] + vec[i];
            
            for (int i = 0; i < m; ++i) {
                long long target = vec[i];
                long long left = target * i - prefix[i];
                long long right = prefix[m] - prefix[i + 1] - target * (m - 1 - i);
                ans[target] = left + right;
            }
        }

        return ans;
    }
};
// Input: [1, 2, 1, 1]
// Output: [5, 0, 3, 4]
// prefix sum: [0, 3, 4, 5]
// prefix sum of index: [0, 1, 3, 6]