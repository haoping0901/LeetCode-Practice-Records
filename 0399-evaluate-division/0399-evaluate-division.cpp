class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> rec;

        // record the equations
        for (int i=0; i<values.size(); i++) {
            rec[equations[i][0]][equations[i][1]] = values[i];
            rec[equations[i][1]][equations[i][0]] = 1/values[i];
        }

        vector<double> ret(queries.size(), -1);
        deque<pair<string, double>> q;
        unordered_map<string, bool> visited;

        for (int i=0; i<queries.size(); i++) {
            string operand1 = queries[i][0], operand2 = queries[i][1];
            if (rec.count(operand1) == 0) {
                continue;
            } else if (operand1.compare(operand2) == 0) {
                ret[i] = 1;
            }

            bool find_ans = false;
            visited[operand1] = true;

            for (const pair<string, double> equation: rec[operand1]) {
                if (equation.first.compare(operand2) == 0) {
                    ret[i] = equation.second;
                    find_ans = true;
                    break;
                }

                q.push_back(make_pair(equation.first, equation.second));
            }

            // BFS
            while (!q.empty() && !find_ans) {
                if (visited[q.front().first] || rec.count(q.front().first) == 0) {
                    q.pop_front();
                    continue;
                }

                visited[q.front().first] = true;
                for (const pair<string, double> equation: rec[q.front().first]) {
                    if (equation.first.compare(operand2) == 0) {
                        ret[i] = q.front().second*equation.second;
                        find_ans = true;
                        break;
                    }

                    q.push_back(make_pair(equation.first, q.front().second*equation.second));
                }
                q.pop_front();
            }

            q.clear();
            visited.clear();
        }

        return ret;
    }
};