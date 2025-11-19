class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        // sliding window: 每次計算 [n, n+k-1] meeting 區間中，與此區間前後的 free space 加總
        // 第一次計算需考慮前後，後續只需新增後面的 free space
        // 超過 k 時，需剃除前面的 free space，並更新開頭
        int ret = 0;
        int cnt = 0;
        int l_idx = 0, r_idx = 0;
        int time_len = startTime.size();

        while (r_idx < time_len) {
            // 更新 window
            if (r_idx - l_idx == k) {
                if (l_idx > 0)
                    cnt -= startTime[l_idx] - endTime[l_idx - 1];
                else
                    cnt -= startTime[l_idx];
                ++l_idx;
            }

            // 計算 free space
            if (r_idx == 0) {
                cnt += startTime[l_idx];
            }
            if (r_idx + 1 < time_len) {
                cnt += startTime[r_idx + 1] - endTime[r_idx];
            } else {
                cnt += eventTime - endTime[r_idx];
            }

            if (cnt > ret)
                ret = cnt;

            ++r_idx;
        }

        return ret;
    }
};