class Solution {
public:
    string convert(string s, int numRows) {
        // cycle_num = numRows + (numRows-2)
        // 1st column: (char % (numRows+(numRows-2))) == 0
        // 2nd column: (char % (numRows+(numRows-2))) == 1 (2-1) && cycle_num-1
        // nth column: (char % (numRows+(numRows-2))) == n-1 && cycle_num-(n-1), where (n-1) < (cycle_num-i)
        
        if (numRows == 1) 
            return s;
        
        int cycle_num = numRows + (numRows-2);
        string ret;

        for (int i=0; i<numRows; i++) {
            int idx = i;
            
            while (idx < s.length()) {
                if ((i < (cycle_num-i)) && (i != 0)) {
                    ret.push_back(s.at(idx));
                    if ((idx-i+cycle_num-i) < s.length()) {
                        ret.push_back(s.at(idx-i+cycle_num-i));
                    }
                    idx += cycle_num;
                } else {
                    ret.push_back(s.at(idx));
                    idx += cycle_num;
                }
            }
        }

        return ret;
    }
};