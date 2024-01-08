class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int h = triangle.size();
        vector<int> pre(h, triangle[0][0]), cur(h, triangle[0][0]);

        for (int i=1; i<h; i++) {
            cur[0] = pre[0] + triangle[i][0];
            for (int j=1; j<triangle[i].size()-1; j++) {
                cur[j] = pre[j-1] < pre[j] ? triangle[i][j]+pre[j-1] : triangle[i][j]+pre[j];
            }
            cur[triangle[i].size()-1] = triangle[i][triangle[i].size()-1] + pre[triangle[i].size()-2];
            
            for (int j=0; j<h; j++) pre[j] = cur[j];
        }

        int ret = cur[0];
        for (const int& c: cur) ret = c < ret ? c : ret;

        return ret;
    }
};