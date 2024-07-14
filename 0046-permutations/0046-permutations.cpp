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

            // Select a candidate and pass the remaining candidates for the 
            // next permutation.
            candidates.pop_front();
            permuted_nums.push_back(selected_num);
            FindPermutations(candidates, permuted_nums);

            // Put the selected candidate back, as it will be needed again 
            // when selecting other candidates.
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