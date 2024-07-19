class Solution {
    int n_parens_;
    vector<string> ret_;
public:
    void findCombinations(const int& l_parens, const int& r_parens, 
                          string& cur_comb) {
        // If the number of right parentheses is equal to n, then the current 
        // combination recorded is one of the answers.
        if (r_parens == n_parens_) {
            ret_.push_back(cur_comb);
            return;
        }

        // If the number of left parentheses is less than n, then add a left 
        // parenthesis to the current recorded combination.
        if (l_parens < n_parens_) {
            cur_comb.push_back('(');
            findCombinations(l_parens+1, r_parens, cur_comb);
            cur_comb.pop_back();
        }

        // If the number of right parentheses is less than the number of left 
        // parentheses, then add a right parenthesis to the current recorded 
        // combination.
        if (r_parens < l_parens) {
            cur_comb.push_back(')');
            findCombinations(l_parens, r_parens+1, cur_comb);
            cur_comb.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        n_parens_ = n;
        // The number of right parentheses should not exceed the number of 
        // left parentheses.
        /*  n = 2
                          (
                ((                  ()
              X    (()         ()(     X
                (())   X   ()()    X
        */
        string _;
        findCombinations(0, 0, _);

        return ret_;
    }
};