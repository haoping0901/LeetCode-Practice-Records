class Solution {
public:
    int compress(vector<char>& chars) {
        char ch=chars.at(0);
        int pin_idx=0, cnt=1, vec_len=chars.size();

        for (int i=1; i<vec_len; i++) {
            while (i < vec_len && chars.at(pin_idx+cnt) == ch) {
                i++;
                cnt++;
            }

            if (cnt > 1) {
                chars.erase(chars.begin()+pin_idx+1, chars.begin()+pin_idx+cnt);
                
                string s = to_string(cnt);
                vector<char> units2vec(s.begin(), s.end());
                chars.insert(chars.begin()+pin_idx+1, units2vec.begin(), units2vec.end());
                
                cnt = 1;
                pin_idx += 1 + s.length();
            } else {
                pin_idx++;
            }

            if (pin_idx < chars.size())
                ch = chars.at(pin_idx);
        }

        return chars.size();
    }
};