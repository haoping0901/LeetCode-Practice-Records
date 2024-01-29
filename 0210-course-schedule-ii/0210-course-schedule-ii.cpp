class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ret;
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> next_courses(numCourses, vector<int>());

        // initialize the graph recording the order and record the
        // indegree of each courses
        for (const vector<int>& p: prerequisites) {
            indegree[p[0]]++;
            next_courses[p[1]].push_back(p[0]);
        }

        // iterate and record the courses with 0 indegree, and update indegree record
        for (int i=0; i<numCourses; i++) {
            if (indegree[i] == 0) ret.push_back(i);
        }

        for (int i=0; i<ret.size(); i++) {
            for (const int& nc: next_courses[ret[i]]) {
                indegree[nc]--;

                if (indegree[nc] == 0) ret.push_back(nc);
            }
        }

        if (ret.size() != numCourses)
            return vector<int>();
        return ret;
    }
};