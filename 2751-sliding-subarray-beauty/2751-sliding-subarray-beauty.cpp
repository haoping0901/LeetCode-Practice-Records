class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        // sliding window + multiset
        // sliding window: sub array
        // multiset: get the x-th smallest integer
        size_t i;
        vector<int> ret;
        multiset<int> min_x_nums;
        multiset<int> other_nums;

        // iterate nums
        // from k-th num check x-th smallest num

        for (i = 0; i < nums.size(); ++i) {
            if (min_x_nums.size() < x) {
                min_x_nums.insert(nums[i]);
            } else {
                int min_tail = *min_x_nums.rbegin();
                if (nums[i] < min_tail) {
                    other_nums.insert(min_tail);
                    min_x_nums.erase(min_x_nums.find(min_tail));
                    min_x_nums.insert(nums[i]);
                } else
                    other_nums.insert(nums[i]);
            }

            if (min_x_nums.size() + other_nums.size() == k) {
                ret.push_back(min(*min_x_nums.rbegin(), 0));

                /* erase num become out of range in next iteration */
                int erase_num = nums[i-k+1];
                auto erase_it = other_nums.find(erase_num);

                if (erase_it != other_nums.end()) {
                    other_nums.erase(erase_it);
                } else {
                    erase_it = min_x_nums.find(erase_num);
                    min_x_nums.erase(erase_it);

                    if (!other_nums.empty()) {
                        min_x_nums.insert(*other_nums.begin());
                        other_nums.erase(other_nums.begin());
                    }
                }
            }
        }

        return ret;
    }
};