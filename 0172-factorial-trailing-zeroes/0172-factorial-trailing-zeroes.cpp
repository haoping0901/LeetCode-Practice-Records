class Solution {
public:
    int trailingZeroes(int n) {
        int five_cnt = 0;
        int check_five = 5;

        // Check the exponent of the number 5 in the prime factorization of 
        // the input factorial.
        while (n / check_five > 0) {
            five_cnt += n / check_five;

            // Check the exponents of the higher powers of the number 5
            check_five *= 5;
        }

        return five_cnt;
    }
};