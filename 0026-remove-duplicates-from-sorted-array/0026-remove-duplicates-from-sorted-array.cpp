class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // two pointers
        // p1: length of the returned nums
        // p2: the current index being checked
        auto p1 = nums.begin(), p2 = p1 + 1;

        // iterate through all nums
        // when the value at p2 differs from p1, record this value at the next 
        // position of p1, and update p1
        while (p2 != nums.end()) {
            if (*p2 != *p1) {
                ++p1;
                *p1 = *p2;
            }
            ++p2;
        }

        return p1 - nums.begin() + 1;
    }
};