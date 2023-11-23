class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int cnt=0, max;

        for (int i=0; i<k; i++) {
            cnt += nums.at(i);
        }
        max = cnt;

        for (int i=k; i<nums.size(); i++) {
            cnt -= nums.at(i-k) - nums.at(i);

            if (cnt > max) {
                max = cnt;
            }
        }

        return (double) max/k;
    }
};