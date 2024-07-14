class Solution {
    int n_, k_;
    vector<vector<int>> ret;
public:
    void MakeCombination(const int& round, const int& start_num, 
                         vector<int>& new_combination) {
        if (round == k_+1) {
            ret.push_back(new_combination);
            return;
        }

        for (int num = start_num; num <= n_-k_+round; ++num) {
            new_combination.push_back(num);
            MakeCombination(round+1, num+1, new_combination);
            new_combination.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        // round 1: [1], [2], [3 (n - k + round)]
        // round 2: [1, 2], [1, 3], [1, 4], [2, 3], [2, 4], 
        //          [3, 4 (n - k + round)]

        // Create new possible combinations for each round.
        // The for loop needs an additional condition to add new 
        // combination vectors.
        // Consider the constraint that n only lies in the range [1, 20].
        // We choose the recursive approach.
        // int upper_bound = n - k;
        // for (int round = 1; round <= upper_bound+round; ++round) {}
        
        n_ = n, k_ = k;
        vector<int> new_combination;
        MakeCombination(1, 1, new_combination);

        return ret;
    }
};