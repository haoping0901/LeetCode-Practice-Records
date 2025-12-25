class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        // Target: min length of two non-overlapping subarray's sum are same
        // with target
        // si > target -> find sn == si - target
        unordered_map<int, int> rec;
        int ans, sum, n = arr.size(), min_len;
        vector<int> prefix(n, n + 1), suffix(n, n + 1);

        rec[0] = -1;
        sum = 0;
        min_len = n;
        for (int i = 0; i < n; ++i) {
            sum += arr[i];

            auto it = rec.find(sum - target);
            if (it != rec.end())
                min_len = min(min_len, i - it->second);
            
            rec[sum] = i;
            prefix[i] = min_len;
        }

        rec.clear();
        rec[0] = n;
        sum = 0;
        min_len = n;
        for (int i = n - 1; i >= 0; --i) {
            sum += arr[i];

            auto it = rec.find(sum - target);
            if (it != rec.end())
                min_len = min(min_len, it->second - i);
            
            rec[sum] = i;
            suffix[i] = min_len;
        }

        ans = n + 1;
        for (int i = 0; i < n - 1; ++i)
            ans = min(ans, prefix[i] + suffix[i + 1]);
        
        return ans == n + 1 ? -1 : ans;
    }
};
// Input: [1, 2, 4, 3, 7], target = 7