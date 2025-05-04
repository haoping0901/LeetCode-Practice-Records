class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        // O(n)
        // 從頭往後加總 k 個數字並判斷平均是否 >= threshold
        // 每次去掉開頭，加上新結尾再計算平軍並記錄有沒有大於等於 threshold
        unsigned sum = 0;
        unsigned cnt = 0;
        size_t start = 0;
        size_t idx;

        for (idx = 0; idx < k - 1; ++idx) {
            sum += arr[idx];
        }

        for (idx = k - 1; idx < arr.size(); ++idx, ++start) {
            sum += arr[idx];

            if (sum / k >= threshold)
                ++cnt;

            sum -= arr[start];
        }

        return cnt;
    }
};