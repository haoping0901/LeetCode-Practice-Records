class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // First, check if it is feasible.
        if (m*n != original.size()) return {};

        auto cols = original.size() / m;
        vector<vector<int>> ret;
        
        // Push back each row into the return value one by one.
        for (auto iter=original.begin(); iter != original.end(); iter+=cols) 
            ret.push_back(vector<int>(iter, iter+cols));

        return ret;
    }
};