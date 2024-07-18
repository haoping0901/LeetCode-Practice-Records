class Solution {
public:
    string countOfAtoms(string formula) {
        int str_len = formula.length(), vec_idx = 0;
        vector<pair<string, int>> rec;
        stack<int> parenthesis_rec;

        for (int idx=0; idx<str_len; ++idx) {
            string element;
            element.push_back(formula[idx]);
            
            // Uppercase
            if (isupper(formula[idx])) {
                // extract the element
                ++idx;
                while (idx < str_len && islower(formula[idx])) {
                    element.push_back(formula[idx++]);
                }

                // extract the count
                int count = 0;
                while (idx < str_len && isdigit(formula[idx])) {
                    count = count*10 + (formula[idx++] - '0');
                }
                count = (count == 0) ? 1 : count;
                --idx; // Adjust the index to be incremented in each iteration.

                rec.push_back({element, count});
                vec_idx++;
            } else if (formula[idx] == '(') {
                // right parenthesis
                // record the index in rec vector by stack
                parenthesis_rec.push(vec_idx);
            } else if (formula[idx] == ')') {
                // left parenthesis
                // extract the count (if exists)
                ++idx;
                int count = 0;
                while (idx < str_len && isdigit(formula[idx])) 
                    count = count*10 + (formula[idx++] - '0');
                count = (count == 0) ? 1 : count;
                --idx; // Adjust the index to be incremented in each iteration.

                // Multiply all the counts at and after the index recorded on 
                // the top of the stack by the count.
                for (int i=vec_idx-1; i>=parenthesis_rec.top(); --i) 
                    rec[i].second *= count;
                
                parenthesis_rec.pop();
            }
        }

        sort(rec.begin(), rec.end());

        string ret, cmp_str = rec[0].first;

        // Merge duplicate elements.
        for (int i=1; i<vec_idx; ++i) {
            if (rec[i].first == cmp_str) {
                rec[i].second += rec[i-1].second;
                rec[i-1].second = 0;
            } else
                cmp_str = rec[i].first;
        }

        // generate the return string
        for (int i=0; i<vec_idx; ++i) {
            if (rec[i].second == 0)
                continue;
            else if (rec[i].second == 1)
                ret += rec[i].first;
            else
                ret += rec[i].first + to_string(rec[i].second);
        }

        return ret;
    }
};