class Solution {
public:
    int searchSubInterval(const vector<int>& nums, int l, int r, const int& target) {
        while (l <= r) {
            int m = l + ((r-l) >> 1);

            if (nums[m] < target)
                l = m+1;
            else
                r = m-1;
        }

        if (nums[l] == target)
            return l;
        else
            return -1;
    }

    int search(vector<int>& nums, int target) {
        int tail_idx = nums.size()-1, l = 0, r = tail_idx;

        // find the starting position before rotating
        while (l <= r) {
            int m = l + ((r-l) >> 1);

            if (nums[m] >= nums[0])
                l = m+1;
            else 
                r = m-1;
        }
        
        l = l % nums.size();

        // check which interval target value is located and search it
        if (nums[tail_idx] < target)
            return searchSubInterval(nums, 0, l-1, target);
        else
            return searchSubInterval(nums, l, tail_idx, target);
    }
};