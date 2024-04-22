int searchInsert(int* nums, int numsSize, int target) {
    int l = 0, r = numsSize-1, pivot = l + ((r-l) >> 1);

    while (l < r) {
        if (nums[pivot] < target)
            l = pivot + 1;
        else 
            r = pivot;

        pivot = l + ((r-l) >> 1);
    }

    return (nums[pivot] < target) ? pivot+1 : pivot;
}