class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ret;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> rec;
        int len2 = nums2.size();

        for (const int& num1: nums1) rec.push({num1+nums2[0], 0});

        while (k && !rec.empty()) {
            int idx2 = rec.top().second;
            int num2 = nums2[idx2];
            int num1 = rec.top().first - num2;
            rec.pop();
            k--;

            ret.push_back({num1, num2});
            if (idx2+1 < len2) rec.push({num1+nums2[idx2+1], idx2+1});
        }

        return ret;
    }
};