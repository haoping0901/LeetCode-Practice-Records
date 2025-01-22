class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // Greedy
        // Each time, select the project with the maximum profit from those 
        // with capital <= w.
        // As explained in the discussion section of the problem, starting a 
        // new project does not reduce the available capital.

        // Use a min_heap to organize projects, allowing us to efficiently 
        // locate projects where capital <= w.
        auto capital_cmp = [](const pair<int, int>& a, 
                              const pair<int, int>& b) {
            return a.first > b.first;
        };
        priority_queue<pair<int, int>, 
                       vector<pair<int, int>>, 
                       decltype(capital_cmp)> capital_heap(capital_cmp);
        for (int idx=0; idx<profits.size(); ++idx) {
            capital_heap.push({capital[idx], profits[idx]});
        }

        auto profits_cmp = [](const pair<int, int>& a, 
                              const pair<int, int>& b) {
            return a.second < b.second;
        };
        priority_queue<int> profits_heap;
        while (k--) {
            while (!capital_heap.empty() && capital_heap.top().first <= w) {
                profits_heap.push(capital_heap.top().second);
                capital_heap.pop();
            }

            if (profits_heap.empty()) {
                break;
            } else {
                // After selecting the project with the highest profit, update w so 
                // that in the next selection, we can include candidate projects that 
                // satisfy the updated capital <= w condition.
                w += profits_heap.top();
                profits_heap.pop();
            }
        }

        return w;
    }
};