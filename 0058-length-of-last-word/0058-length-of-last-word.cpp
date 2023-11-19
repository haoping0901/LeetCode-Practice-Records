class Solution {
public:
    int lengthOfLastWord(string s) {
        for (int i=s.length()-1; i>=0; i--) {
            if (s[i] == ' ') {
                s.pop_back();
            } else {
                break;
            }
        }

        size_t pos = s.rfind(' ');

        if (pos == string::npos)
            return s.length();
        else {
            return s.substr(pos).length() - 1;
        }
    }
};