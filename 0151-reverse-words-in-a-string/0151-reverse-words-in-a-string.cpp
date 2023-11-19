class Solution {
public:
    string reverseWords(string s) {
        // Reverse whole string
        reverse(s.begin(), s.end());

        // trim the space in the front
        int cnt = 0;
        
        for (int i=0; i<s.length(); i++) {
            if (s.at(i) == ' ') {
                cnt++;
            } else {
                break;
            }
        }
        s.erase(s.begin(), s.begin()+cnt);

        // trim the space in the end
        cnt = 0;
        for (string::iterator it=s.end()-1; it!=s.begin(); it--) {
            if (*it == ' ') {
                cnt++;
            } else {
                break;
            }
        }
        s.erase(s.end()-cnt, s.end());

        // trim the consecutive space among the string
        int pin_pos = 0, str_len = s.length();

        for (int i=pin_pos; i<s.length(); i++) {
            cnt = 0;
            if (s.at(i) == ' ') {
                cout << "i: " << i << endl;
                pin_pos = i;
                i++;
                while (i<str_len && s.at(i) == ' ') {
                    cnt++;
                    i++;
                }
                
                i -= cnt;
                
                s.erase(s.begin()+pin_pos, s.begin()+pin_pos+cnt);
                pin_pos++;
            }
        }

        // reverse each word
        for (int i=0; i<s.length(); i++) {
            if (s.at(i) != ' ') {
                pin_pos = i;
                i++;
                while (i<s.length() && s.at(i) != ' ') {
                    i++;
                }

                if (i == s.length()) {
                    reverse(s.begin()+pin_pos, s.end());
                } else {
                    reverse(s.begin()+pin_pos, s.begin()+i);
                }
            }
        }
        
        return s;
    }
};