class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int courses_wo_cycle = numCourses;
        vector<vector<int>> rec(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        deque<int> q;

        // record the prerequisites of each course
        // p1 -> p0
        for (const vector<int>& p: prerequisites) {
            rec[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        // start checking whether the topology exists cycle from 
        // the courses that have 0 indegree
        for (int i=0; i<numCourses; i++) {
            if (indegree[i] == 0) {
                q.push_back(i);
                courses_wo_cycle--;
            }
        }

        while (!q.empty()) {
            for (const int& next_course: rec[q.front()]) {
                indegree[next_course]--;

                if (indegree[next_course] == 0) {
                    q.push_back(next_course);
                    courses_wo_cycle--;
                }
            }

            q.pop_front();
        }

        return !courses_wo_cycle;
    }
};