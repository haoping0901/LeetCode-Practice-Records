class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        // stable: [i, j], j - i + 1 >= 3
        // ni == nj == n[i + 1, .. , j - 1]
        // s[j] - s[i + 1] == nj == ni, j - i + 1 >= 3
        // ni == nj
        // ni + s[i + 1] == nj == s[j]
        
        unordered_map<long long, unordered_map<int, int>> rec;
        long long sum, pre, ans = 0;

        pre = sum = capacity[0];
        for (int i = 1; i < capacity.size(); ++i) {
            sum += capacity[i];

            if (i >= 2) {
                long long target = sum - (capacity[i] << 1);
                ans += rec[target][capacity[i]];
            }

            ++rec[pre][capacity[i - 1]];
            pre = sum;
        }

        return ans;
    }
};
// Input: [9, 3, 2, 1, 3, 9]
// Output: 2