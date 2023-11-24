/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        uint left=1, right=n;
        uint guess_num = (left+right) / 2;
        uint result = guess(guess_num);

        while (result != 0) {
            if (result == 1) {
                left = guess_num + 1;
                guess_num = (left+right) / 2;
            } else {
                right = guess_num - 1;
                guess_num = (left+right) / 2;
            }
            result = guess(guess_num);
        }

        return guess_num;
    }
};