class Solution {
public:
    int distinctPoints(string s, int k) {
        unordered_map<int, unordered_set<int>> rec;
        int l = 0, r = 0;
        int ret = 0;
        vector<int> cur_pos(2, 0);
        char dir;

        // Record coordinate before remove
        for (r = 0; r < s.length(); ++r) {
            dir = s[r - l];

            // record current position
            if (dir == 'U')
                ++cur_pos[1];
            else if (dir == 'D')
                --cur_pos[1];
            else if (dir == 'L')
                --cur_pos[0];
            else if (dir == 'R')
                ++cur_pos[0];
        }

        // Remove step in sliding window
        for (r = 0; r < s.length(); ++r) {
            dir = s[r];
            // 移除 window 區間的 step
            if (dir == 'U')
                --cur_pos[1];
            else if (dir == 'D')
                ++cur_pos[1];
            else if (dir == 'L')
                ++cur_pos[0];
            else if (dir == 'R')
                --cur_pos[0];

            if (r >= k - 1) {
                // check unique cnt
                if (rec[cur_pos[0]].find(cur_pos[1]) == rec[cur_pos[0]].end()) {
                    rec[cur_pos[0]].insert(cur_pos[1]);
                    ++ret;
                }

                // 加回 window 區間的 step
                dir = s[r - k + 1];

                if (dir == 'U')
                    ++cur_pos[1];
                else if (dir == 'D')
                    --cur_pos[1];
                else if (dir == 'L')
                    --cur_pos[0];
                else if (dir == 'R')
                    ++cur_pos[0];
            }
        }

        return ret;
    }
};