class Solution {
    bool IsDivisibleBy2(const int& num) const {
        return num & 1;
    }
public:
    bool checkIfExist(vector<int>& arr) {
        // brute force: n^2
            // for each numbers, we iterate all numbers to find the target 
            // number
        
        // sort and binary search: nlogn + logn
        
        // set: nlogn

        // unordered_multiset: n
        unordered_multiset<int> rec(arr.begin(), arr.end());

        for (auto it=rec.begin(); it!=rec.end(); ++it) {
            if (*it == 0) {
                if (rec.count(*it) > 1)
                    return true;
            } else if (rec.find(*it << 1) != rec.end())
                return true;
            else if (!IsDivisibleBy2(*it) && rec.find(*it >> 1) != rec.end())
                return true;
        }
        
        return false;
    }
};