class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        // Input: arr of n elements
            // exactly n - 2 element are special num
            // 1: sum of special numbers
            // 1: outlier
                // not one of special num or sum
        // Target: return largest potential outlier
            // find the num that is two times of sum which is substract by outlier
                // record all sum that is substract by outlier (O(n))
                // check if one of element times two appeared in rec
        // Brute force:
            // Sum all num
            // iterate all elements, sel each num as outlier and substract it from sum
            // iterate all other elements, check if after substract it from sum, the sum 
            // will be equal to the sel num
        unordered_map<int, int> rec;
        int sum = 0, ret = -1000;

        for (const auto& n: nums) {
            sum += n;
            ++rec[n << 1];
        }

        for (const auto& n: nums) {
            int tmp = sum - n;
            if (rec[tmp] > 1 || rec[tmp] == 1 && tmp != n << 1)
                ret = max(ret, n);
        }

        return ret;
    }
};