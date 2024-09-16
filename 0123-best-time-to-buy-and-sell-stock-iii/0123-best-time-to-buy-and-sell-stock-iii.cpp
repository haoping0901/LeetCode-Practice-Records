class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[times, idx] = max(dp[k, idx-1], prices[i] - prices[j] 
        //                      + dp[times-1, j-1]), j = [0..i-1]
        vector<vector<int>> dp(3, vector<int>(prices.size(), 0));
        for (int times=1; times<=2; ++times) {
            int cur_min = prices[0];
            for (int idx=1; idx<prices.size(); ++idx) {
                // select the minimum of the combination betweeen 
                // prices[j] - dp[times-1][j-1]: the lower the better
                //  prices[j]       : the lower the better
                //  dp[times-1][j-1]: the higher the better 
                cur_min = min(cur_min, prices[idx-1] - dp[times-1][idx-1]);
                dp[times][idx] = max(dp[times][idx-1], prices[idx] - cur_min);
            }
        }

        return dp[2][prices.size()-1];
    }
};