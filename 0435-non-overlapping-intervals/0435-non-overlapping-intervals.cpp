class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int prev = 0, cnt = 0;
        for (int cur = 1; cur<intervals.size(); cur++) {

            // check whether the overlap existed
            if (intervals[cur][0] < intervals[prev][1]) {
                cnt++;

                // only leave the interval with the smaller end (we've sorted the intervals
                // , so we can ignore the start)
                if (intervals[cur][1] < intervals[prev][1]) prev = cur;
            } else {
                prev = cur;
            }
        }

        return cnt;
    }
};