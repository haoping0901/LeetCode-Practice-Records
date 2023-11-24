class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = nums.at(0);

        for (int i=1; i<nums.size(); i++) {
            ret = ret ^ nums.at(i);
        }
        return ret;
    }
};