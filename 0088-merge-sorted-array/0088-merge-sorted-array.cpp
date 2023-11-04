class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1=m-1, idx2=n-1, sorted_idx=m+n-1;

        while (idx2 >= 0) {
            if ((idx1 >= 0) && (nums1.at(idx1) > nums2.at(idx2))) {
                nums1.at(sorted_idx) = nums1.at(idx1);
                sorted_idx--;
                idx1--;
            } else {
                nums1.at(sorted_idx) = nums2.at(idx2);
                sorted_idx--;
                idx2--;
            }
        }
    }
};