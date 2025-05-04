class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // input: points, k cards can take (from the begin or the end)
        // two pointers, slide to end
        ssize_t head_idx;
        size_t tail_idx;
        unsigned max_score;
        unsigned n_tail = 1;
        unsigned sum = 0;

        for (head_idx = 0; head_idx < k; ++head_idx) {
            sum += cardPoints[head_idx];
        }

        max_score = sum;
        for (head_idx = k - 1, tail_idx = cardPoints.size() - 1; head_idx >= 0; 
                --head_idx, --tail_idx) {
            sum = sum - cardPoints[head_idx] + cardPoints[tail_idx];
            max_score = max(max_score, sum);
        }

        return max_score;
    }
};