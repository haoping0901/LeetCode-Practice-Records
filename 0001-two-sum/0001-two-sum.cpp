class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int complement;
        unordered_map<int, int> hash_idx;

        for (int i=0; i<nums.size() ; i++) {
            complement = target - nums[i];

            if (hash_idx.count(complement))
                return {hash_idx[complement], i};
            hash_idx[nums[i]] = i;
        }
        
        return {};
    }
};