class Solution {
public:
    string addBinary(string a, string b) {
        int carry_in = 0, idx_a, idx_b;
        string ret;

        for (idx_a=a.size()-1, idx_b=b.size()-1; idx_a>=0 && idx_b>=0; idx_a--, idx_b--) {
            int bit_a = a[idx_a] - '0', bit_b = b[idx_b] - '0';

            ret.push_back((char) (bit_a ^ bit_b ^ carry_in) + '0');
            carry_in = bit_a & bit_b | bit_a & carry_in | bit_b & carry_in;
        }

        while (idx_a >= 0) {
            int bit_a = a[idx_a--] - '0';
            
            ret.push_back((char) (bit_a ^ carry_in) + '0');
            carry_in = carry_in & bit_a;
        }

        while (idx_b >= 0) {
            int bit_b = b[idx_b--] - '0';
            
            ret.push_back((char) (bit_b ^ carry_in) + '0');
            carry_in = carry_in & bit_b;
        }

        if (carry_in) ret.push_back((char) carry_in + '0');
        
        reverse(ret.begin(), ret.end());
        return ret;
    }
};