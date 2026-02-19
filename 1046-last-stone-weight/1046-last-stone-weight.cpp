class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (const int st : stones)
            pq.push(st);
        
        while (pq.size() > 1) {
            int st1, st2;

            st1 = pq.top();
            pq.pop();
            st2 = pq.top();
            pq.pop();

            st1 = abs(st1 - st2);

            if (st1 > 0)
                pq.push(st1);
        }

        return pq.size() == 0 ? 0 : pq.top();
    }
};