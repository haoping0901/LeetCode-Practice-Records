class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int hold=-prices.at(0), profit=0;

        for (int i=1; i<prices.size(); i++) {
            int tmp=hold;
            hold = max(hold, profit-prices.at(i));
            profit = max(profit, tmp+prices.at(i)-fee);
        }
        
        return profit;
    }
};