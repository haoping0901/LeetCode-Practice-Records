class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        // Target: (ti + tj) % 60 == 0, i < j
        // for each time tn, record the time need to make it divisible by 60
            // {60 - (tn % 60)(tsp), cnt} => unordered_map rec
            // ++rec[tsp]
            // ret += rec[60 - tsp]
        unordered_map<int, int> rec;
        int ret = 0;
        int tsp;

        for (int t: time) {
            tsp = t % 60;

            ret += rec[(60 - tsp) % 60];
            ++rec[tsp];
        }
        
        return ret;
    }
};