class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            vector<string> ret;
            return ret;
        }

        string s2("abc"), s3("def"), s4("ghi"), s5("jkl"), s6("mno");
        string s7("pqrs"), s8("tuv"), s9("wxyz");

        int string_amt=1;
        vector<string> strings;
        for (const char& digit: digits) {
            switch (digit) {
                case '2':
                    strings.push_back(s2);
                    string_amt *= 3;
                    break;
                case '3':
                    strings.push_back(s3);
                    string_amt *= 3;
                    break;
                case '4':
                    strings.push_back(s4);
                    string_amt *= 3;
                    break;
                case '5':
                    strings.push_back(s5);
                    string_amt *= 3;
                    break;
                case '6':
                    strings.push_back(s6);
                    string_amt *= 3;
                    break;
                case '8':
                    strings.push_back(s8);
                    string_amt *= 3;
                    break;
                case '7':
                    strings.push_back(s7);
                    string_amt *= 4;
                    break;
                case '9':
                    strings.push_back(s9);
                    string_amt *= 4;
                    break;
            }
        }

        vector<string> ret(string_amt);

        // ad-ghi ae-ghi af-ghi bd-ghi
        // i=0: s2_loop: s3_len*s4_len
        // i=1: s3_loop: s4_len
        // i=2: s4_loop: 1
        int loop = string_amt;
        for (int i=0; i<digits.length(); i++) {
            string tmp = strings.at(i);
            loop /= tmp.length();
            int idx=0;

            while (idx < string_amt) {
                for (int j=0; j<tmp.length(); j++) {
                    for (int k=0; k<loop; k++) {
                        ret[idx+k].push_back(tmp.at(j));
                    }
                    idx += loop;
                }
            }
        }
        
        return ret;
    }
};