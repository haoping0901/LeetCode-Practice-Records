class Solution {
public:
    bool MeetCondition(const string &s) {
        bool ret = true;

        switch (s[0]) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            break;
        default:
            ret = false;
        }

        switch (s[s.length() - 1]) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            break;
        default:
            ret = false;
        }

        return ret;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // queries[i] = [li, ri]: find the number of strings at
        // indices [li, ri] of words that start and end with char. {a, e, i, o, u}
        // Target: return vec. of ans of queries
        // prefix sum:
        int n = words.size(), nq = queries.size();
        vector<int> prefix(n + 1);
        vector<int> ans(nq);

        // Iterate words,
            // sum and records the word that meets the query to an arr. (prefix)
        for (int i = 0; i < n; ++i) {
            if (MeetCondition(words[i]))
                ++prefix[i + 1];
            prefix[i + 1] += prefix[i];
        }
        // [1, 1, 1]

        // For each query [li, ri]
            // rec. the diff of prefix[ri + 1] - prefix[li] to return arr.
        for (int i = 0; i < nq; ++i)
            ans[i] = prefix[queries[i][1] + 1] - prefix[queries[i][0]];

        return ans;
    }
};
// words:   ["a", "b", "c"]
// queries: [[1, 2], [0, 2]]
// return:  [0, 1]
