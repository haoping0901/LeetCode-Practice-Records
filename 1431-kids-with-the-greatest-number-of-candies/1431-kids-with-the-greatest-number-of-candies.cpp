class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> rec(candies.size(), false);
        int max=0;

        for (const int& candy: candies) {
            if (candy > max) {
                max = candy;
            }
        }

        for (int i=0; i<candies.size(); i++) {
            if (candies[i]+extraCandies >= max) {
                rec[i] = true;
            }
        }

        return rec;
    }
};