class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int right = 0;
        for (const int& b: piles) {
            if (b > right) right = b;
        }
        
        int left = 1;
        while (left < right) {
            int eat_rate = (left+right) / 2, hours = 0;

            for (const int& b: piles) {
                hours += b/eat_rate;
                if (b%eat_rate > 0) hours++;
            }

            if (hours > h) {
                left = eat_rate + 1;
            } else {
                right = eat_rate;
            }
        }

        return left;
    }
};