class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ret = 0;
        unordered_map<int, bool> rec;

        for (const int& n: nums) 
            rec[n] = false;
        
        for (int n: nums) {
            int n_consecutive = 1, check_n = n;

            // check consecutive number before
            while (rec.count(--check_n) && !rec[check_n]) {
                rec[check_n] = true;
                n_consecutive++;
            }

            // check consecutive number after
            check_n = n;
            while (rec.count(++check_n) && !rec[check_n]) {
                rec[check_n] = true;
                n_consecutive++;
            }
            
            ret = max(ret, n_consecutive);
            rec[n] = true;
        }
        
        return ret;
    }
};