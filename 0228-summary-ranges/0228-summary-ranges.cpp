class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        string s;
        int nums_len = nums.size();

        if (nums_len == 0)
            return ret;

        int begin=0, diff=nums.at(0);

        for (int i=0; i<nums_len; i++) {
            if (nums.at(i) != i+diff) {
                if (begin != i-1) {
                    s = to_string(nums.at(begin)) + "->" + to_string(nums.at(i-1));
                } else {
                    s = to_string(nums.at(begin));
                }
                
                ret.push_back(s);
                begin = i;
                diff = nums.at(i)-i;
            } 
        }

        if (begin == nums_len-1) {
            s = to_string(nums.at(begin));
        } else {
            s = to_string(nums.at(begin)) + "->" + to_string(nums.at(nums_len-1));
        }
        ret.push_back(s);

        return ret;
    }
};