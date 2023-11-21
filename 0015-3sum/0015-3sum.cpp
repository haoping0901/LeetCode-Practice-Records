class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort + tri-pointer
        sort(nums.begin(), nums.end());

        int lptr=0, rptr=nums.size()-1, mptr;
        vector<vector<int>> ret;

        while ((lptr+2) <= nums.size()-1) {
            
            for (mptr=lptr+1; mptr<rptr; mptr++) {
                int sum = nums.at(lptr) + nums.at(mptr) + nums.at(rptr);
                if (sum > 0) {
                    rptr--;
                    mptr--;
                    while (mptr < rptr && nums.at(rptr) == nums.at(rptr+1)) {
                        rptr--;
                    }
                } else if (sum == 0) {
                    vector<int> ans {nums.at(lptr), nums.at(mptr), nums.at(rptr)};
                    ret.push_back(ans);
                    rptr--;
                    while (mptr < rptr && nums.at(rptr) == nums.at(rptr+1)) {
                        rptr--;
                    }
                    
                    while (mptr < rptr && nums.at(mptr) == nums.at(mptr+1)) {
                        mptr++;
                    }
                }
            }

            lptr++;

            // skip the same value to avoid recording the same answer
            while ((lptr+2) <= nums.size()-1 && nums.at(lptr) == nums.at(lptr-1)) {
                lptr++;
            }
            rptr = nums.size()-1;
        }

        return ret;
    }
};