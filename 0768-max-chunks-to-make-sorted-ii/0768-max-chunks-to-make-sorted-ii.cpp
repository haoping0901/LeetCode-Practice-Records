class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // max number of individual sorted chunks that generate an ascending arr
        stack<int> st;

        for (const int n : arr) {
            if (st.empty() || n >= st.top()) {
                st.push(n);
            } else {
                int top = st.top();
                while (!st.empty() && st.top() > n)
                    st.pop();
                st.push(top);
            }
        }

        return st.size();
    }
};

// [3, 2, 4, 5, 1] -> 1
    // [3] 5, [3] 4, [3, 4] 4, [3, 4, 5] 4, [5] 1
// [3, 2, 4, 1, 5] -> 2
    // [3] 5, [3] 4, [3, 4] 4, [4] 2, [4, 5] 2
// [3, 1, 2, 5, 4] -> 2
// [4, 1, 3, 2, 5] -> 2
    // [4] 5, [4] 4, [4] 3, [4] 2, [4, 5] 2
// [2, 1, 4, 3, 5] -> 3
    // [2] 5, [2] 4, [2, 4] 4, [2, 4] 3, [2, 4, 5] 3
