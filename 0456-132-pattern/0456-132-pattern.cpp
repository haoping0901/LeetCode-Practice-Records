class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // Check if nums contains 132 pattern
            // 132 pattern: nums[i] < nums[k] < nums[j], i < j < k
        // brute force: triple loop, fix ni, find nj > ni, then find nk < nj && nk > ni
        // Iterate nums, and find nk that appears in ranges of all {ni, nj} pair that:
            // ni < nj, i < j
        // Find some way can record and extract the range
            // binary search the list of ni, nj pair -> nlogn
        stack<int> st;
        int k = INT_MIN;

        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < k)
                return true;
            
            while (!st.empty() && st.top() < nums[i]) {
                k = max(k, st.top());
                st.pop();
            }
            st.push(nums[i]);
        }

        return false;
    }
};
// [2, 4, 1, 3]
// [2, 4, 1, 5, 3]
// [2, 4, 1, 0, 3]
// [2, 4, -2, 1, -1]
// [2, 4, -2, -1, 1]
// [5, 4]