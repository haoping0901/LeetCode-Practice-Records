class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // 總和最大的區間，該區間數字不重複 => set
        // sliding window
        unordered_set<int> rec;
        unsigned cnt = 0;
        unsigned ret = 0;

        for (size_t beg = 0, end = 0; end < nums.size(); ++end) {
            if (rec.find(nums[end]) != rec.end()) {
                while (nums[beg] != nums[end]) {
                    cnt -= nums[beg];
                    rec.erase(nums[beg]);
                    ++beg;
                }
                ++beg;
            } else {
                cnt += nums[end];
                rec.insert(nums[end]);
            }

            ret = max(ret, cnt);
        }

        return ret;
    }
};