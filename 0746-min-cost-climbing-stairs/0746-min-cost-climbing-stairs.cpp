class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> rec(cost.size()+1, 0);

        rec.at(0) = 0;
        rec.at(1) = 0;

        for (int i=2; i<=cost.size(); i++) {
            rec[i] = (cost[i-2]+rec[i-2] <= cost[i-1]+rec[i-1]) \
                       ? cost[i-2]+rec[i-2] : cost[i-1]+rec[i-1];
        }

        return rec.back();
    }
};