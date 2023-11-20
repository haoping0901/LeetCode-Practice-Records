class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lptr=0, rptr=numbers.size()-1;
        int sum = numbers.at(lptr) + numbers.at(rptr);

        while (sum != target) {
            if (sum > target) {
                rptr--;
            } else if (sum < target) {
                lptr++;
            } else {
                break;
            }

            sum = numbers.at(lptr) + numbers.at(rptr);
        }

        vector<int> ret;
        ret.push_back(lptr+1);
        ret.push_back(rptr+1);

        return ret; 
    }
};