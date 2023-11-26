class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price=prices.at(0), max_price=prices.at(0), max_profit=0;

        for (const int& price: prices) {
            if (price < min_price) {
                min_price = price;
                max_price = price;
            } else if (price > max_price) {
                max_price = price;
                if (max_price-min_price > max_profit)
                    max_profit = max_price - min_price;
            }
        }

        return max_profit;
    }
};