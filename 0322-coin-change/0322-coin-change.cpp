class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> rec(amount+1, -1);
        rec[0] = 0;

        // initialize the record vector
        for (const int& coin: coins) {
            if (coin > amount) continue;

            rec[coin] = 1;
        }

        for (int i=1; i<amount; i++) {
            // case there's no combination can generate this summation
            if (rec[i] == -1) continue;

            for (const int& coin: coins) {
                long long tmp = (long long) i + coin;

                if (tmp > amount) continue;

                rec[tmp] = rec[tmp] == -1 ? rec[i]+1 : min(rec[i]+1, rec[tmp]);
            }
        }

        return rec[amount];
    }
};