class Solution {
public:
    bool is_vowel_letter(char ch) {
        switch(ch) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
                break;
            default:
                return false;
                break;
        }
    }

    int maxVowels(string s, int k) {
        int max=0, cnt=0, begin=0;

        for (int i=0; i<s.length(); i++) {
            // update the window range when bigger than k
            if ((i-begin) == k) {
                if (is_vowel_letter(s.at(begin))) {
                    cnt--;
                }
                begin++;
            }

            if (is_vowel_letter(s.at(i))) {
                cnt++;

                if (cnt == k)
                    return k;
                else if (cnt > max) {
                    max = cnt;
                }

            } 
        }

        return max;
    }
};