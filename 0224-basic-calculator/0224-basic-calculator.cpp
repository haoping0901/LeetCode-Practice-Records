class Solution {
public:
    void GetDigit(deque<char>& cal_st, bool& has_neg, int& num, int& sum) {
        while (!cal_st.empty() && isdigit(cal_st.back())) {
            char ch = cal_st.back();
            cal_st.pop_back();

            num *= 10;
            num += ch - '0';
        }

        if (has_neg)
            sum -= num;
        else
            sum += num;
        has_neg = false;
        num = 0;
    }

    int calculate(string s) {
        // ... (6+8) -> ... + 14
        // use another stack to calculate back?
            // (
                // +1
                // 11
                    // (
                    // +4
                    // +5
                    // 2
                // -3
            // )
            // +14
        deque<char> expr_st, cal_st;

        // get the expression
        for (const auto& ch: s) 
            if (ch != ' ')
                expr_st.push_back(ch);
        
        // use another stack to calculate back
        while (!expr_st.empty()) {

            string str;
            bool has_neg = false;
            int sum = 0, num = 0;

            switch (expr_st.back()) {
                case '(':
                    while (cal_st.back() != ')') {
                        char ch = cal_st.back();
                        cal_st.pop_back();
                        if (ch == '-') 
                            has_neg = !has_neg;
                        else if (isdigit(ch)) {
                            num = ch - '0';
                            GetDigit(cal_st, has_neg, num, sum);
                        }
                    }
                    cal_st.pop_back();

                    if (has_neg)
                        sum += num * -1;
                    else 
                        sum += num;
                    str = to_string(sum);
                    for (auto it = str.rbegin(); it != str.rend(); ++it) 
                        cal_st.push_back(*it);
                    
                    expr_st.pop_back();
                    break;
                default:
                    cal_st.push_back(expr_st.back());
                    expr_st.pop_back();
                    break;
            }
        }
        
        bool has_neg = false;
        int sum = 0, num = 0;
        while (!cal_st.empty()) {
            char ch = cal_st.back();
            cal_st.pop_back();

            if (ch == '-') {
                has_neg = !has_neg;
                sum += num;
                num = 0;
            } else if (isdigit(ch)) {
                num = ch - '0';
                GetDigit(cal_st, has_neg, num, sum);
            }
        }

        return has_neg ? sum+ (num * -1) : sum+num;
    }
};