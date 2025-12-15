class Solution {
public:
    int GetMaxDigit(int n) {
        int ret = 0;

        while (n > 0) {
            ret = max(ret, n % 10);
            n /= 10;
        }

        return ret;
    }

    int maxSum(vector<int>& nums) {
        // Input: arr of nums
        // Target: find max sum of pair
            // pair: largest digit of num is the same
        // {max digit, max num}
        unordered_map<int, int> rec;
        int max_digit, ret = -1;

        for (const auto& n: nums) {
            max_digit = GetMaxDigit(n);
            if (rec[max_digit] > 0)
                ret = max(ret, rec[max_digit] + n);

            rec[max_digit] = max(rec[max_digit], n);
        }

        return ret;
    }
};