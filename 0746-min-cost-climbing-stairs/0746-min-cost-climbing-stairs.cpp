class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int c0=0, c1=0, c2;

        for (int i=2; i<=cost.size(); i++) {
            c2 = (cost[i-2]+c0 <= cost[i-1]+c1) ? cost[i-2]+c0 : cost[i-1]+c1;
            c0 = c1;
            c1 = c2;
        }

        return c2;
    }
};