class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        // Target: number of interchangeable rectangle
            // Interchangeable: rectangles that have w to h ratio
            //  (w_i / h_i == w_j / h_j, i != j)
        // Input: array of rectangles size
        // {ratio: amount of rectangles of this ratio}
        unordered_map<double, int> rec;
        long long ret = 0;
        double ratio;

        for (const vector<int>& r: rectangles) {
            ratio = (double)r[0] / r[1];
            
            ret += rec[ratio]++;
        }

        return ret;
    }
};