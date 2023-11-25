class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int left=INT_MAX, mid=INT_MAX;

        for (const int& num: nums) {
            if (num < left)
                left = num;
            else if (num > left && num < mid)
                mid = num;
            else if (num > mid)
                return true;
        }

        return false;
    }
};