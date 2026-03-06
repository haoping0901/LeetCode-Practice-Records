class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long ans = 0;

        for (const int gift : gifts) {
            pq.push(gift);
            ans += gift;
        }
        
        while (k-- > 0) {
            int square = pq.top();
            int root = sqrt(square);

            pq.pop();
            pq.push(root);
            ans -= square - root;
        }

        return ans;
    }
};