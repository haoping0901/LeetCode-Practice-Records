class Solution {
public:
    string simplifyPath(string path) {
        int len = path.length();
        deque<string> rec;

        for (int i=0; i<len; i++) {
            if (path[i] == '/') continue;

            string s;
            
            // record the file name until '/' appears
            while (i<len && path[i] != '/') {
                s += path[i];
                i++;
            }

            // check the file name we've recorded
            if (s == ".")
                continue;
            else if (s == "..") {
                if (!rec.empty())
                    rec.pop_back();
            } else 
                rec.push_back(s);
        }

        string ret;
        while (!rec.empty()) {
            ret += "/" + rec.front();
            rec.pop_front();
        }

        if (ret.length() == 0)
            return "/";

        return ret;
    }
};