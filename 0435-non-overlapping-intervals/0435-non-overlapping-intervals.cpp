class Solution {
    static inline bool CmpSecEleLt(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // [1, 6], [2, 4], [3, 6], [4, 5]
        // [2, 4], [4, 5], [1, 6], [4, 6]

        // sort intervals by end
        sort(intervals.begin(), intervals.end(), CmpSecEleLt);

        // Check whether the end of the current interval is greater than the 
        // start of the next interval.
        int cnt = 0;
        for (int idx=0; idx<intervals.size()-1; ++idx) {
            if (intervals[idx][1] > intervals[idx+1][0]) {
                intervals[idx+1][1] = intervals[idx][1];
                ++cnt;
            }
        }

        return cnt;
    }
};