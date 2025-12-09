class Solution {
public:
    long long calculateScore(string s) {
        // Target: find total score
            // Score: sum(j - i), where s[j] == 'z' - (s[i] - 'a')
        // Input: string s

        // Record the position of each seen alphabet in order
        // Iterate s, check if the mirror (rec_m) exist
            // exist: return (ret) += i - rec_m + 1
            // non-exist: rec the position
        unordered_map<char, deque<int>> rec;
        long long ret = 0;
        int i;

        for (i = 0; i < s.length(); ++i) {
            char mirror = 'z' - (s[i] - 'a');
            if (rec[mirror].empty())
                rec[s[i]].push_back(i);
            else {
                ret += i - rec[mirror].back();
                rec[mirror].pop_back();
            }
        }

        return ret;
    }
};