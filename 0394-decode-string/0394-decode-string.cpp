class Solution {
public:
    string decodeString(string s) {
        int repeat=0;
        string ret;
        stack<int> repeats;
        stack<string> strs;

        for (const char& ch: s) {
            if (isdigit(ch)) {
                repeat = repeat*10 + (ch - '0');
            } else if (ch == '[') {
                repeats.push(repeat);
                strs.push(ret);
                ret.clear();
                repeat = 0;
            } else if (ch == ']') {
                    for (int i=repeats.top(); i>0; i--) {
                        strs.top() += ret;
                    }
                    repeats.pop();

                    ret = strs.top();
                    strs.pop();
            } else {
                ret.push_back(ch);
            }
        }

        return ret;
    }
};