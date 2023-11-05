class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest_len = 0;
        int end = nums.size();

        if (end == 1)
            return true;
        
        for (int i=0; i<end-1; i++) {
            int jump_len = i + nums[i];
            
            if (jump_len > farthest_len)
                farthest_len = jump_len;
            
            if ((farthest_len == i) && (nums.at(i) == 0))
                return false;
        }

        return true;
    }
};