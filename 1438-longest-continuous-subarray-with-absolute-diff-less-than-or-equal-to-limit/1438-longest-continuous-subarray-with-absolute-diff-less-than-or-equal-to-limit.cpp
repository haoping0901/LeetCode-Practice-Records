class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> q_max, q_min;
        int n = nums.size();
        int l = 0, r = 0;
        int ret = 0;

        while (r < n) {
            while (!q_max.empty() && q_max.back() < nums[r])
                q_max.pop_back();
            while (!q_min.empty() && q_min.back() > nums[r])
                q_min.pop_back();
            
            q_max.push_back(nums[r]);
            q_min.push_back(nums[r]);

            while (!q_max.empty() && !q_min.empty() && 
                   (q_max.front() - q_min.front() > limit)) {
                if (q_max.front() == nums[l])
                    q_max.pop_front();
                if (q_min.front() == nums[l])
                    q_min.pop_front();
                
                ++l;
            }

            ret = max(ret, r - l + 1);
            ++r;
        }

        return ret;
    }
};
// [1, 3, 7, 5, 2, 4, 6]
// limit: 3
// 1, 3
// 7
// 7, 5
// 5, 2
// 5, 2, 4
// 4, 6