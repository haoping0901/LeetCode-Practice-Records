class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0, pin_num, pin_pos = 0, nums_len = nums.size();

        for (int i=0; i<nums_len; i++) {
            if (cnt == 0) {
                cnt++;
                pin_num = nums.at(pin_pos);
                pin_pos++;
            } else if ((cnt == 1) && (nums.at(pin_pos) == pin_num)) {
                cnt++;
                pin_pos++;
            } else if ((cnt == 2) && (nums.at(pin_pos) == pin_num)) {
                nums.erase(nums.begin() + pin_pos);
            } else if (nums.at(pin_pos) != pin_num) {
                cnt = 1;
                pin_num = nums.at(pin_pos);
                pin_pos++;
            }
        }

        return pin_pos;
    }
};