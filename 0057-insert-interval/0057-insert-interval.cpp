class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), i = 0;
        vector<vector<int>> ret;

        // 要處理的區間分為
        // 1. 重疊區間前面沒重疊的區間
        // 2. 重疊區間
        // 3. 重疊區間後沒重疊的區間

        // case 1
        while (i < n && intervals[i][1] < newInterval[0]) {
            ret.push_back(intervals[i]);
            i++;
        }

        // case 2
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        ret.push_back(newInterval);

        // case 3
        while (i < n) {
            ret.push_back(intervals[i]);
            i++;
        }

        return ret;
    }
};