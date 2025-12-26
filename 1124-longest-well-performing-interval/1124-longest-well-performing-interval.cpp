class Solution {
public:
    int longestWPI(vector<int>& hours) {
        // Tiring: h > 8
        // Well-performing: in [i, j], number of hx (> 8) > hy (< 8)
        // Target: longest well-performing interval
        int n = hours.size(), ans = 0, sum = 0;
        vector<int> prefix(n + 2);

        for (int i = 0; i < n; ++i) {
            sum += (hours[i] > 8) ? -1 : 1;

            if (sum < 0) {
                ans = i + 1;
            } else {
                if (prefix[sum + 1] > 0)
                    ans = max(ans, i - prefix[sum + 1] + 1);
                
                if (prefix[sum] == 0)
                    prefix[sum] = i + 1;
            }
        }

        return ans;
    }
};
// Input:   [1, 13, 5, 7, 9, 2, 10, 8]
// Output: 3