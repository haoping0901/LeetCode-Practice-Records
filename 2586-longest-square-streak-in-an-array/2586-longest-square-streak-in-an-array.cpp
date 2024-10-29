class Solution {
    int Square(const int& n) const {return n*n;}
public:
    int longestSquareStreak(vector<int>& nums) {
        // Sort nums to ensure that when checking smaller numbers, there's no 
        // need to backtrack to update the streak sequence of larger numbers.
        sort(nums.begin(), nums.end());

        // Use a map to record the current streak for each number.
        int ret = -1;
        map<int, int> rec;
        for (const int& n: nums) {
            // If the square root of num exists in the map, record the value 
            // stored for that num + 1.
            // If it doesn’t exist, set the value to 1.
            int sqrt_val = sqrt(n);

            if (Square(sqrt_val) == n) {
                rec[n] = rec[sqrt_val] + 1;
                ret = max(ret, rec[n]);
            } else
                rec[n] = 1;
        }

        return ret == 1 ? -1 : ret;
    }
};