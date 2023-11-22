class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // unordered_map: record the iterated number
        unordered_map<int, int> rec;
        vector<int> ret;

        for (int i=0; i<nums.size(); i++) {
            if (rec.count(target-nums.at(i)) > 0) {
                ret.push_back(rec.at(target-nums.at(i)));
                ret.push_back(i);
                break;
            } else {
                rec[nums.at(i)] = i;
            }
        }

        return ret;
    }
};