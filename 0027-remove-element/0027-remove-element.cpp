class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int nums_len = nums.size();
        
        for (int i=0; i<nums_len; i++) {
            if (nums.at(i) == val) {
                nums.erase(nums.begin()+i);
                i--;
                nums_len--;
            }
        }

        return nums_len;
    }
};