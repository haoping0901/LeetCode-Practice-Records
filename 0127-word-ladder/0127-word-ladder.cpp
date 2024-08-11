class Solution {
    bool OnlyDifferOneChar(const string& cur_str, const string& next_str) {
        int cnt = 0;
        for (int idx=0; idx<cur_str.length(); ++idx) {
            if (cur_str[idx] != next_str[idx]) {
                if (cnt++ == 1) return false;
            }
        }

        return cnt == 1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // BFS
        // Use a vector to record the indices of the strings that have been 
        // checked.
        // Each time, add strings that differ by only one character and 
        // haven't been checked to the queue for the next round of checks.
        int n_str = wordList.size(), endWord_idx = -1;
        vector<int> seq_rec(n_str, 0);
        deque<pair<int, int>> q;    // [idx, seq]
        q.push_back({-1, 1});

        for (int i=0; i<n_str; ++i) {
            if (wordList[i] == endWord) {
                endWord_idx = i;
                break;
            }
        }
        if (endWord_idx == -1) return 0;

        while (!q.empty()) {
            for (int idx=0; idx<n_str; ++idx) {
                // Determine which strings differ from the specified string by 
                // only one character.
                // If a sequence is shorter, record it and add it to the queue 
                // for the next round of checks.
                if (q.front().first == -1) {    // queue with beginWord
                    if (OnlyDifferOneChar(beginWord, wordList[idx])) {
                        seq_rec[idx] = 2;
                        q.push_back({idx, 2});
                    }
                } else {
                    if (q.front().first == idx) 
                        continue;

                    if (OnlyDifferOneChar(wordList[q.front().first], 
                                          wordList[idx])) {
                        if (seq_rec[idx] == 0) {
                            if (idx == endWord_idx) 
                                return q.front().second + 1;
                            
                            seq_rec[idx] = q.front().second + 1;
                            q.push_back({idx, seq_rec[idx]});
                        }
                    }
                }
            }

            q.pop_front();
        }

        return seq_rec[endWord_idx];
    }
};