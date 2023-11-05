class Solution {
public:
    int jump(vector<int>& nums) {
        int nums_len = nums.size();
        vector<int> rec(nums_len, 0);

        for (int i=0; i<nums_len; i++) {
            for (int j=i+1; j<=(i+nums.at(i)) && j<nums_len; j++) {
                if ((rec.at(j) > (rec.at(i) + 1)) || (rec.at(j) == 0))
                    rec.at(j) = rec.at(i) + 1;
            }
        }

        return rec.at(nums_len-1);
    }
};