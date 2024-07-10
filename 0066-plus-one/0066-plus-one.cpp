class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry_in = 1;
        for (int idx = digits.size()-1; idx >= 0 && carry_in; --idx) {
            digits[idx] +=  carry_in;

            if (digits[idx] == 10) 
                digits[idx] = 0;
            else 
                carry_in = 0;
        }

        if (carry_in) {
            digits.push_back(0);
            digits[0] = carry_in;
        }
        return digits;
    }
};