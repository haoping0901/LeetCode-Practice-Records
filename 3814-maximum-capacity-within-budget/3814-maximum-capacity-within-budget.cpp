class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        vector<pair<int, int>> cc_pair;
        stack<pair<int, int>> st; // cost, capacity
        int ans = 0;

        for (int i = 0; i < costs.size(); ++i) {
            if (costs[i] < budget)
                cc_pair.emplace_back(costs[i], capacity[i]);
        }
        ranges::sort(cc_pair, {}, &pair<int, int>::first);

        st.emplace(0, 0);
        for (const auto& [cost, cap] : cc_pair) {
            while (cost + st.top().first >= budget)
                st.pop();
            
            ans = max(ans, st.top().second + cap);
            if (cap > st.top().second)
                st.emplace(cost, cap);
        }

        return ans;
    }
};
// costs:       [2, 3, 4]
// capacity:    [1, 2, 3]
// budget:      5