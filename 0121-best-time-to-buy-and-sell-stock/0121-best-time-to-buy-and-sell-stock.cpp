class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_diff = -1, buy_cost = -1, profit;

        for(int i=0; i<prices.size(); i++) {
            /* Record the minimum purchase price */
            if (buy_cost == -1) {
                buy_cost = prices[i];
            } else if (prices[i] < buy_cost) {
                buy_cost = prices[i];
            }
            
            profit = prices.at(i) - buy_cost;
            if (profit > max_diff) {
                max_diff = profit;
            }
        }

        return max_diff;
    }
};