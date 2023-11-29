class Solution {
    int target, quota;
public:
    void findCombination(int sum, int cur_quota, int start, vector<int>& rec, vector<vector<int>>& ret) {
        if (sum != target && cur_quota == 0) {
            return;
        } else if (sum == target && cur_quota == 0) {
            ret.push_back(rec);
            return;
        }

        for (int i=start; i<10; i++) {
            rec.push_back(i);
            findCombination(sum+i, cur_quota-1, i+1, rec, ret);
            rec.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        quota = k;
        target = n;
        vector<int> rec;
        vector<vector<int>> ret;

        findCombination(0, k, 1, rec, ret);

        return ret;
    }
};