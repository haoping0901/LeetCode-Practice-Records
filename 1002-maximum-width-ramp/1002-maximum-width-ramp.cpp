class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        deque<int> st({0});

        // Record numbers that form a strictly descending sequence.
        // This allows us to check the maximum interval directly.
        for (int idx=1; idx<nums.size(); ++idx) {
            if (nums[idx] < nums[st.back()])
                st.push_back(idx);
        }

        int max_ramp = 0;
        for (int idx = nums.size()-1; idx > 0; --idx) {
            while (!st.empty() && nums[st.back()] <= nums[idx]) {
                max_ramp = max(max_ramp, idx - st.back());

                // Any subsequent numbers whose maximum interval also ends at 
                // this number will have a smaller interval compared to the 
                // current number being checked. Therefore, we can safely remove this record.
                st.pop_back();
            }
        }

        return max_ramp;
    }
};