class Solution {
    vector<vector<int>> ret;
public:
    void FindPermutations(deque<int>& candidates, vector<int>& permuted_nums) {
        int original_size = candidates.size();
        if (!original_size) {
            ret.push_back(permuted_nums);
            return;
        }

        for (int i=0; i<original_size; ++i) {
            int selected_num = candidates.front();
            candidates.pop_front();
            permuted_nums.push_back(selected_num);
            FindPermutations(candidates, permuted_nums);
            candidates.push_back(selected_num);
            permuted_nums.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        // [1]: [2, 3]
        // [1, 2]: 3
        // [1, 3]: 2
        vector<int> permuted_nums;
        deque<int> candidates(nums.begin(), nums.end());
        FindPermutations(candidates, permuted_nums);

        return ret;
    }
};