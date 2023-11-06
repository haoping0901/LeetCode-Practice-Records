class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nums_len=nums.size();
        int pin=0, cnt=0;

        for (int i=0; i<nums_len; i++) {
            int cur_cnt = 0;

            while ((pin+1) < (nums_len-cnt)) {
                if (nums.at(pin) == nums.at(pin+cur_cnt+1)) {
                    i++;
                    cur_cnt++;
                    cnt++;
                } else {
                    break;
                }
            }
            
            if (cur_cnt > 0)
                nums.erase(nums.begin()+(pin+1), nums.begin()+(pin+1)+cur_cnt);
            
            pin++;
        }

        return (nums_len - cnt);
    }
};