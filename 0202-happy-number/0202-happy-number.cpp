class Solution {
public:
    int calculateHappyNumber(int n) {
        int next_n = 0;

        while (n > 0) {
            next_n += pow(n%10, 2);
            n /= 10;
        }

        return next_n;
    }

    bool isHappy(int n) {
        int slow, fast;

        slow = calculateHappyNumber(n);
        fast = calculateHappyNumber(slow);

        while (slow != fast) {
            slow = calculateHappyNumber(slow);
            fast = calculateHappyNumber(calculateHappyNumber(fast));
        }
        
        return (slow == 1) ? true : false;
    }
};