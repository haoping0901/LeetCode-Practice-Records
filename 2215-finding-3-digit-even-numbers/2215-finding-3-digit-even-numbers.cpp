class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        // input: array of digits
        // output: 3-digit even numbers
            // first digit can not be 0
            // 3-th digit should be even
        // count number of each digit in digits
        unsigned i;
        unsigned j;
        unsigned k;
        unsigned num;
        vector<int> digits_cnt(10, 0);
        vector<int> ret;
        for (const int& digit: digits)
            ++digits_cnt[digit];
    
        // DFS: each iter select the min digit have not been selected
        for (i = 1; i < 10; ++i) {
            if (digits_cnt[i] == 0)
                continue;
            
            num = i * 10;
            --digits_cnt[i];
            for (j = 0; j < 10; ++j) {
                if (digits_cnt[j] == 0)
                    continue;
                
                num += j;
                --digits_cnt[j];
                for (k = 0; k < 10; ++k) {
                    if (digits_cnt[k] == 0 || k & 0x1)
                        continue;
                    
                    ret.push_back(num * 10 + k);
                }
                ++digits_cnt[j];
                num -= j;
            }
            ++digits_cnt[i];
        }

        return ret;
    }
};