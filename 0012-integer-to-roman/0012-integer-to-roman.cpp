class Solution {
public:
    string intToRoman(int num) {
        string roman;
        
        /* 1000 */
        int quotient = num/1000;
        for (int i=0; i<quotient; i++) {
            roman.append("M");
        }
        num -= (quotient*1000);

        /* 900 */
        quotient = num/900;
        for (int i=0; i<quotient; i++) {
            roman.append("CM");
        }
        num -= (quotient*900);

        /* 500 */
        quotient = num/500;
        for (int i=0; i<quotient; i++) {
            roman.append("D");
        }
        num -= (quotient*500);

        /* 400 */
        quotient = num/400;
        for (int i=0; i<quotient; i++) {
            roman.append("CD");
        }
        num -= (quotient*400);

        /* 100 */
        quotient = num/100;
        for (int i=0; i<quotient; i++) {
            roman.append("C");
        }
        num -= (quotient*100);

        /* 90 */
        quotient = num/90;
        for (int i=0; i<quotient; i++) {
            roman.append("XC");
        }
        num -= (quotient*90);

        /* 50 */
        quotient = num/50;
        for (int i=0; i<quotient; i++) {
            roman.append("L");
        }
        num -= (quotient*50);

        /* 40 */
        quotient = num/40;
        for (int i=0; i<quotient; i++) {
            roman.append("XL");
        }
        num -= (quotient*40);

        /* 10 */
        quotient = num/10;
        for (int i=0; i<quotient; i++) {
            roman.append("X");
        }
        num -= (quotient*10);

        /* 9 */
        quotient = num/9;
        for (int i=0; i<quotient; i++) {
            roman.append("IX");
        }
        num -= (quotient*9);

        /* 5 */
        quotient = num/5;
        for (int i=0; i<quotient; i++) {
            roman.append("V");
        }
        num -= (quotient*5);

        /* 4 */
        quotient = num/4;
        for (int i=0; i<quotient; i++) {
            roman.append("IV");
        }
        num -= (quotient*4);

        /* 1 */
        for (int i=0; i<num; i++) {
            roman.append("I");
        }

        return roman;
    }
};