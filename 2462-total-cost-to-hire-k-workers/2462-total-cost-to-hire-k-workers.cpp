class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int rptr, lptr;
        long long ret = 0;
        priority_queue<int, vector<int>, greater<int>> l_pq, r_pq;

        for (rptr = costs.size()-1, lptr = 0; lptr<rptr && lptr < candidates; lptr++, rptr--) {
            l_pq.push(costs[lptr]);
            r_pq.push(costs[rptr]);
        }
        if (lptr == rptr && lptr < candidates) {
            l_pq.push(costs[lptr]);
            lptr++;
        }

        for (int i=0; i<k; i++) {
            if (!l_pq.empty() && !r_pq.empty()) {
                if (l_pq.top() <= r_pq.top()) {
                    ret += l_pq.top();
                    l_pq.pop();

                    if (lptr <= rptr && l_pq.size() < candidates) {
                        l_pq.push(costs[lptr]);
                        lptr++;
                    }
                } else {
                    ret += r_pq.top();
                    r_pq.pop();

                    if (lptr <= rptr && r_pq.size() < candidates) {
                        r_pq.push(costs[rptr]);
                        rptr--;
                    }
                }
            } else {
                if (l_pq.empty()) {
                    ret += r_pq.top();
                    r_pq.pop();
                } else {
                    ret += l_pq.top();
                    l_pq.pop();
                }
            }
        }

        return ret;
    }
};