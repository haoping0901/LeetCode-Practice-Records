class Solution {
public:
    int findMin(vector<int>& nums) {
        int front=0, end=nums.size()-1;

        if (front == end)
            return nums.at(front);
        while (front != (end-1)) {
            int pivot = (end+front) / 2;
            if (nums.at(pivot) < nums.at(end)) {
                end = pivot;
            } else if (nums.at(pivot) > nums.at(end)) {
                front = pivot;
            }
        }

        return min(nums.at(front), nums.at(end));
    }
};