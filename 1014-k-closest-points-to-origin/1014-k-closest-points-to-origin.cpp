class Solution {
    double GetDistance(const vector<int>& point) const {
        return sqrt(pow(point[0], 2) + pow(point[1], 2));
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // min_heap: 記錄並排序各個點離原點的距離
        priority_queue<pair<double, int>, 
                       vector<pair<double, int>>, 
                       greater<pair<double, int>>> min_heap; 
        
        for (int idx=0; idx<points.size(); ++idx) {
            min_heap.push({GetDistance(points[idx]), idx});
        }

        vector<vector<int>> ret;
        while (!min_heap.empty() && k--) {
            auto point = min_heap.top();
            min_heap.pop();

            ret.push_back(points[point.second]);
        }

        return ret;
    }
};