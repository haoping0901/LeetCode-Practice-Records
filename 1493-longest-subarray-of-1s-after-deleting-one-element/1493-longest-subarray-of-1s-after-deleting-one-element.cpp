class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start = 0, cnt = 0, zeros = 0;

        for (int i=0; i<nums.size(); i++) {
            zeros += (nums[i] == 0);

            while (zeros > 1) {
                zeros -= (nums[start] == 0);
                start++;
            }

            cnt = max(cnt, i-start);
        }
        
        return cnt;
    }

};