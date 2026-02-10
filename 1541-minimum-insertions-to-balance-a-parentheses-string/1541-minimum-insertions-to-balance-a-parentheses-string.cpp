class Solution {
public:
    int minInsertions(string s) {
        // balanced pair: "())"
        // number of '))' before '(' after removing balanced pair
        // number of ')'
        // number of '(' after removing balanced pair
        int add_cnt = 0; // 
        int need = 0; // number of '(' needed

        for (const char ch : s) {
            if (ch == '(') {
                need += 2; // need 2 '('

                if ((need & 0x1) == 0x1) {
                    ++add_cnt; // add a ')'
                    --need;
                }
            } else { // ')'
                --need;

                if (need == -1) { // meet an extra ')'
                    ++add_cnt; // add a '('
                    need = 1; // need a '('
                }
            }
        }

        return add_cnt + need;
    }
};