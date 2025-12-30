class Solution {
public:
    int FindTarget(vector<int>& nums, int target) {
        int l, m, r;

        l = 0;
        r = nums.size();
        while (l < r) {
            m = l + ((r - l) >> 1);

            // (l, r]
            if (nums[m] >= target)
                r = m;
            else
                l = m + 1;
        }

        return l;
    }

    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        // Target: return difference of each element in q between 
        // all elements in n
            // ret[i] = abs(qi - nj), 0 < j < m, m is nums' size
        // sort nums
        // record the prefix sum of sorted nums
        // for each queries qn
            // find the first ni >= qn
            // for num in range [0, i - 1] => ans += i * qn - s[i]
            // for num in range [i, m - 1] => ans += s[m] - s[i] - (m - i) * qn
        int n = nums.size(), m = queries.size();
        vector<long long> prefix(n + 1), ans(m);
        long long sum = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + nums[i];
        
        for (int i = 0; i < m; ++i) {
            long long target = FindTarget(nums, queries[i]);
            long long left = target * queries[i] - prefix[target];
            long long right = prefix[n] - prefix[target] - (n - target) * queries[i];

            ans[i] = left + right;
        }

        return ans;
    }
};
// Input:
// nums:    [1, 2, 3, 4]
// queries: [1, 2, 3, 4]
// Output:  [6, 4, 4, 6]
// prefix of nums:  [1, 3, 6, 10]