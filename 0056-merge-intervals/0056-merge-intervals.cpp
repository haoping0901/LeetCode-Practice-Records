class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len = intervals.size(), idx = 0;
        sort(intervals.begin(), intervals.end());

        for (int i=1; i<len; i++) {
            if (intervals[idx][1] >= intervals[i][0])
                intervals[idx][1] = max(intervals[idx][1], intervals[i][1]);
            else {
                idx++;
                intervals[idx][0] = intervals[i][0];
                intervals[idx][1] = intervals[i][1];
            }
        }

        return vector<vector<int>> (intervals.begin(), intervals.begin()+idx+1);
    }
};