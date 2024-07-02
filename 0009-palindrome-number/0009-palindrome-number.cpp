class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long long cpy_x = x, y = 0;

        // reverse the input number
        while (cpy_x > 0) {
            y = y*10 + cpy_x%10;
            cpy_x /= 10;
        }
        
        return y == x;
    }
};