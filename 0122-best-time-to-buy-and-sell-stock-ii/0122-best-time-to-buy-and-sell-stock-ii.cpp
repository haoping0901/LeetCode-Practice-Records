class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1)
            return 0;

        int sum = 0, max_profit=0;
        int min_price = prices.at(0), prices_len = prices.size();
        
        for (int i=1; i<prices_len; i++) {
            int cur_profit = prices.at(i) - min_price;

            if (prices.at(i) < min_price) {
                min_price = prices.at(i);
                sum += max_profit;
                max_profit = 0;
            } else if (cur_profit > max_profit) {
                max_profit = cur_profit;
            } else if (cur_profit < max_profit) {
                sum += max_profit;
                max_profit = 0;
                min_price = prices.at(i);
            }
        }
        sum += max_profit;

        return sum;
    }
};