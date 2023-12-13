class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int visited_rooms = rooms.size()-1;
        unordered_map<int, bool> rec;
        deque<int> q;

        for (const int& key: rooms.at(0)) {
            q.push_back(key);
        }
        rec[0] = true;
        
        // bfs
        while (!q.empty()) {
            if (rec.count(q.front())) {
                q.pop_front();
            } else {
                rec[q.front()] = true;
                visited_rooms--;

                for (const int& key: rooms[q.front()]) {
                    if (rec.count(key) == 0) {
                        q.push_back(key);
                    }
                }
                q.pop_front();
            }
        }

        return !visited_rooms;
    }
};