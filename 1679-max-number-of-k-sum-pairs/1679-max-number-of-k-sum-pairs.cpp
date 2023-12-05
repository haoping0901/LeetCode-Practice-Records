class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map <int, int> rec;
        int cnt=0;

        for (const int& num: nums) {
            if (rec.count(k-num) == 0) {
                if (rec.count(num) == 0) {
                    rec[num] = 1;
                } else {
                    rec[num]++;
                }
            } else {
                if (rec[k-num] > 0) {
                    rec[k-num]--;
                    cnt++;
                } else {
                    rec[num]++;
                }
            }
        }

        return cnt;
    }
};