class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        // Sliding window
        // Target: sub str ([l, r] window) that can construct word2
        vector<int> w1(26, 0), w2(26, 0);
        long long ret = 0;
        int l = 0, r, n1 = word1.length();
        int idx, i;
        bool found;
        
        // Check number of each ch in word2 (we need to find this
        // amount in word1)
        for (const char& c: word2)
            ++w2[c - 'a'];

        for (r = 0; r < n1; ++r) {
            idx = word1[r] - 'a';
            --w2[idx];

            // Check if found the sub str
            found = true;
            for (i = 0; i < 26; ++i) {
                if (w2[i] > 0) {
                    found = false;
                    break;
                }
            }

            if (found == true) {
                while (w2[word1[l] - 'a'] <= 0) {
                    idx = word1[l] - 'a';
                    ret += n1 - r;
                    ++w2[idx];
                    ++l;

                    if (w2[idx] > 0)
                        break;
                }
            }
        }

        return ret;
    }
};