class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        // 用 min heap 紀錄各方法當前的修車數 {rank, n}
        // 每次挑最早修完車的方法修下一台車
        long long time = 0;

        auto min_heap_cmp = [](const pair<long long, int>& a, 
                               const pair<long long, int>& b){
            return a.first * a.second * a.second > b.first * b.second * b.second;
        };
        priority_queue<pair<long long, int>, 
                       vector<pair<long long, int>>, 
                       decltype(min_heap_cmp)> min_heap(min_heap_cmp);

        for (const int& r: ranks) {
            min_heap.push({r, 1});
        }
        

        while (cars--) {
            auto sel_mech = min_heap.top();
            int rank = sel_mech.first;
            int n = sel_mech.second;
            time = (long long)rank * n * n;

            min_heap.pop();
            min_heap.push({rank, n + 1});
        }

        return time;
    }
};