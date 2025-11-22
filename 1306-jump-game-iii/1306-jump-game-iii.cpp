class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        unordered_set<int> visited;
        deque<int> q;
        int n = arr.size();

        q.push_back(start);
        while (arr[start] != 0 && !q.empty()) {
            start = q.front();
            q.pop_front();
            if (arr[start] == 0)
                break;

            if (visited.find(start) != visited.end())
                continue;
            
            visited.insert(start);

            int next = start - arr[start];
            if (next >= 0 && visited.find(next) == visited.end())
                q.push_back(next);
            
            next = start + arr[start];
            if (next < n && visited.find(next) == visited.end())
                q.push_back(next);

        }

        return (arr[start] == 0);
    }
};