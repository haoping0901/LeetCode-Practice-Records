class Solution {
public:
    bool isValid(string s) {
        deque<char> rec;
        
        for (const char& ch: s) {
            if (ch == ')') {
                if (rec.empty() || rec.back() != '(') return false;
                
                rec.pop_back();
            } else if (ch == ']') {
                if (rec.empty() || rec.back() != '[') return false;
                
                rec.pop_back();
            } else if (ch == '}') {
                if (rec.empty() || rec.back() != '{') return false;
                
                rec.pop_back();
            } else
                rec.push_back(ch);
        }

        if (rec.empty()) return true;
        return false;
    }
};