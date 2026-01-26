class Solution {
public:
    string removeDuplicates(string s, int k) {
        string ans;
        vector<int> cnt(26);
        int l = 0, r = 0;

        for (const char c : s) {
            int cnt_idx = c - 'a';

            if (r - l + 1 < k) {
                ans.push_back(c);
                ++cnt[cnt_idx];
                ++r;
            } else {
                if (cnt[cnt_idx] == k - 1) {
                    // k = 2, l = 3, r = 4
                    while (cnt[cnt_idx] > 0) {
                        --cnt[cnt_idx];
                        --r;
                        ans.pop_back();
                    }
                    // k = 2, r = l = 3
                    // -> l = 2, r = 3
                    while (l > 0 && r - l + 1 < k) {
                        --l;
                        ++cnt[ans[l] - 'a'];
                    }
                } else {
                    --cnt[ans[l++] - 'a'];
                    ++cnt[cnt_idx];
                    ans.push_back(c);
                    ++r;
                }
            }
        }

        return ans;
    }
};