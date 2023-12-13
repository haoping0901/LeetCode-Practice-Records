class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ret = 0;
        vector<bool> visited(isConnected.size(), false);
        deque<int> q;
    
        // bfs 
        for (int i=0; i<isConnected.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                for (int j=i+1; j<isConnected.size(); j++) {
                    if (isConnected[i][j] && !visited[j]){
                        q.push_back(j);}
                }

                while (!q.empty()) {
                    visited[q.front()] = true;

                    for (int j=0; j<isConnected.size(); j++) {
                        if (isConnected[q.front()][j] && !visited[j]) {
                            q.push_back(j);
                        }
                    }
                    q.pop_front();
                }

                ret++;
            }
        }

        return ret;
    }
};