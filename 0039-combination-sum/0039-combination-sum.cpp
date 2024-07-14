class Solution {
    int target_, sum_;
    vector<vector<int>> ret;
public:
    void Combine(vector<int>& candidates, vector<int>& cur_comb, const int& sel_idx) {
        if (sum_ == target_) {
            ret.push_back(cur_comb);
            return;
        }

        for (int idx = sel_idx; idx < candidates.size(); ++idx) {
            if (sum_ + candidates[idx] <= target_) {
                sum_ += candidates[idx];
                cur_comb.push_back(candidates[idx]);
                Combine(candidates, cur_comb, idx);
                sum_ -= candidates[idx];
                cur_comb.pop_back();
            } else 
                break;
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 2, 2, 2 -> x
        // 2, 2, 3
        // 2, 2, 6 -> x
        // Select the value until the summation exceeds the target.
        // Record the index of selected value, which is the starting finding 
        // range for next combination.
        target_ = target, sum_ = 0;
        vector<int> cur_comb;
        sort(candidates.begin(), candidates.end());
        Combine(candidates, cur_comb, 0);

        return ret;
    }
};