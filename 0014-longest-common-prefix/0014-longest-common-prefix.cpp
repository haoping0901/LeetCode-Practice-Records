class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_len = 200;
        char cmp_char;
        if (strs.at(0).length() == 0)
            return "";
        else {
            min_len = strs.at(0).length();
            cmp_char = strs.at(0)[0];
        }
        string ret_str;

        for (int str_idx=1; str_idx<strs.size(); str_idx++) {
            if (strs.at(str_idx).length() == 0)
                return "";

            // record the min length of the strings
            if (strs.at(str_idx).length() < min_len) {
                min_len = strs.at(str_idx).length();
            }

            // compare the first character
            if (strs.at(str_idx)[0] != cmp_char) {
                return "";
            }
        }
        ret_str.push_back(cmp_char);

        // compare the characters without recording minimum length
        for (int i=1; i<min_len; i++) {
            cmp_char = strs.at(0)[i];

            for (int str_idx=1; str_idx<strs.size(); str_idx++) {
                if (strs.at(str_idx)[i] != cmp_char)
                    return ret_str;
            }
            ret_str.push_back(cmp_char);
        }
        
        return ret_str;
    }
};