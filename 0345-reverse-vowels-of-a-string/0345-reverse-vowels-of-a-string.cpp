class Solution {
public:
    bool isVowels(const char& ch) {
        switch (ch) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                return true;
                break;
            default:
                return false;
                break;
        }
    }

    string reverseVowels(string s) {
        int left=0, right=s.length()-1;
        
        while (left < right) {
            if (isVowels(s.at(left)) && isVowels(s.at(right))) {
                char tmp=s.at(left);
                s.at(left) = s.at(right);
                s.at(right) = tmp;
                left++;
                right--;
            } else {
                if (!isVowels(s.at(left)))
                    left++;
                
                if (!isVowels(s.at(right))) 
                    right--;
            }
        }

        return s;
    }
};