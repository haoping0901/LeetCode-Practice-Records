class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() == 0)
            return true;

        for (int i=0; i<s.length(); i++) {
            if (((s.at(i) < 'A') || (s.at(i) > 'Z')) && ((s.at(i) < 'a') || (s.at(i) > 'z')) \
                && ((s.at(i) < '0') || s.at(i) > '9')) {
                s.erase(s.begin()+i);
                i--;
            }
        }

        for (int lidx=0, ridx=s.length()-1; lidx<=ridx; lidx++, ridx--) {
            if (tolower(s.at(lidx)) != tolower(s.at(ridx)))
                return false;
        }
        return true;
    }
};