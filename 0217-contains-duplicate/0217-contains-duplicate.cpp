class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> rec;

        for (const int& num: nums) {
            if (rec.count(num) > 0)
                return true;
            else 
                rec[num] = true;
        }
        
        return false;
    }
};