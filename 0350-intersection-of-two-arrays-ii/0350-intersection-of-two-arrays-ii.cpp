class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int idx1 = 0, idx2 = 0;
        vector<int> ret;
        while (idx1 < nums1.size() && idx2 < nums2.size()) {
            if (nums1[idx1] < nums2[idx2])
                ++idx1;
            else if (nums1[idx1] > nums2[idx2])
                ++idx2;
            else {
                ret.push_back(nums1[idx1]);
                ++idx1, ++idx2;
            }
        }

        return ret;
    }
};