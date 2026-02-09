class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        // Target: min(max(depth(A), depth(B)))
        // Iterate seq, and record the max depth
        // Take the sub seq of which depth > max depth / 2 as part of A
        int max_dep = 0, boundary;
        int cnt_l = 0;
        int n = seq.length();
        vector<int> ans(n);

        for (const char ch : seq) {
            if (ch == '(')
                ++cnt_l;
            else
                --cnt_l;
            
            max_dep = max(max_dep, cnt_l);
        }

        boundary = max_dep >> 1;
        cnt_l = 0;
        for (int i = 0; i < n; ++i) {
            if (seq[i] == '(') {
                ++cnt_l;

                if (cnt_l > boundary)
                    ans[i] = 1;
            } else {
                if (cnt_l > boundary)
                    ans[i] = 1;

                --cnt_l;
            }
        }

        return ans;
    }
};