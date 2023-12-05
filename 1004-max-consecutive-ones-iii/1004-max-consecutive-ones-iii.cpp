class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero_cnt = 0, start = 0, max;

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 0) {
                zero_cnt++;

                if (zero_cnt > k) {
                    while (nums[start] != 0) {
                        start++;
                    }
                    zero_cnt--;
                    start++;
                }
            } 

            max = ((i-start+1) > max) ? (i-start+1) : max;
        }

        return max;
    }
};