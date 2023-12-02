class Solution {
public:
    string decodeString(string s) {
        stack<char> rec;
        string ret;

        for (const char& ch: s) {
            if (ch == ']') {
                string str;

                // get the string from stack till '['
                while (rec.top() != '[') {
                    str.push_back(rec.top());
                    rec.pop();
                }
                rec.pop();

                // copy them n times
                int digit=1, repeats=0;
                while (!rec.empty() && rec.top() >= '0' && rec.top() <= '9') {
                    repeats += (rec.top()-'0') * digit;
                    digit *= 10;
                    rec.pop();
                }

                string tmp;
                for (int i=0; i<repeats; i++) {
                    tmp += str;
                }
                reverse(tmp.begin(), tmp.end());

                // push them back to the stack
                for (const char& t: tmp) {
                    rec.push(t);
                }
            } else {
                rec.push(ch);
            }
        }

        while (!rec.empty()) {
            ret.push_back(rec.top());
            rec.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};