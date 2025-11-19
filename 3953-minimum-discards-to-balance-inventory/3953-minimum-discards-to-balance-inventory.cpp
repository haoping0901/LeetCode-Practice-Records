class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        // arrivals: kept / discarded
        // w: window 大小
        // m: window 中最多可包含相同 arrivals 的上限
        int idx;
        int ret = 0;

        // 紀錄 window 中各個數出現的次數 => unordered_map
        unordered_map<int, int> rec;

        for (idx = 0; idx < arrivals.size(); ++idx) {
            if (idx >= w && arrivals[idx - w] != 0) {
                --rec[arrivals[idx - w]];
            }

            if (++rec[arrivals[idx]] > m) {
                ++ret;
                --rec[arrivals[idx]];
                arrivals[idx] = 0;
            }
        }

        return ret;
    }
};