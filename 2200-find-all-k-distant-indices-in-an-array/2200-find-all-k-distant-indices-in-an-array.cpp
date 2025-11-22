class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ret;
        int nums_size = nums.size();

        for (int i = 0; i < nums_size; ++i) {
            int limit = min(i + k + 1, nums_size);
            for (int j = i; j < limit; ++j) {
                if (nums[j] == key) {
                    limit = min(j + k + 1, nums_size);
                    for (int m = i; m < limit; ++m) {
                        ret.push_back(m);
                        if (nums[m] == key)
                            limit = min(m + k + 1, nums_size);
                    }
                    i = limit - 1;
                    break;
                }
            }
        }

        return ret;
    }
};