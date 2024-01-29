class Solution {
    int n, len;
public:
    pair<int, int> GetCoor(const int& pos) {
        int row = n - pos/n - 1, col;
        if (pos%(n*2) >= n) // right -> left
            col = n - pos%n - 1;
        else 
            col = pos%n;

        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        len = n*n;
        vector<int> steps(len, 512);
        deque<int> q;

        // initialize the queue
        q.push_back(0);
        steps[0] = 0;

        // only check the end of maximum steps and the destination of ladder or snake
        while (!q.empty()) {
            int pos = q.front(), next_start = -1;

            for (int i=pos+1; i<=min(pos+6, len-1); i++) {
                if (i == len-1) return steps[pos]+1;

                pair<int, int> next_coor = GetCoor(i);
                int jump_pos = board[next_coor.first][next_coor.second];

                if (jump_pos-1 == len-1)
                    return steps[pos]+1;
                else if (jump_pos == -1) {
                    steps[i] = min(steps[i], steps[pos]+1);
                    next_start = i;
                } else {
                    if (steps[pos]+1 < steps[jump_pos-1]) {
                        q.push_back(jump_pos-1);
                        steps[jump_pos-1] = steps[pos]+1;
                    }
                }
            }
            if (next_start != -1)
                q.push_back(next_start);

            q.pop_front();
        }

        if (steps[len-1] == 512)
            return -1;
        return steps[len-1];
    }
};