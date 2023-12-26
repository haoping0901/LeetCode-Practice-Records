class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int cnt = 1, begin = points[0][0], end = points[0][1];
        for (const vector<int>& point: points) {
            if (point[0] <= end && point[0] >= begin) {
                begin = point[0];

                if (point[1] < end) end = point[1];
            } else {
                cnt++;
                begin = point[0];
                end = point[1];
            }
        }

        return cnt;
    }
};