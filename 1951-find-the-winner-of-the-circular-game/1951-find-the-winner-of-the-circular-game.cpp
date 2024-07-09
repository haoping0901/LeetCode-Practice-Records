class Solution {
public:
    int findTheWinner(int n, int k) {
        // 1, X, 3, 4, 5 -> 4, X, 1, 2, 3
        // idx_sub = (idx - k + n) % n
        // 1, 2, 3, 4 -> 3, 4, 5, 1
        // (idx_sub + k) % n = idx
        int rec = 0;
        for (int n_friends = 2; n_friends <= n; ++n_friends) 
            rec = (rec + k) % n_friends;
        
        // 1, 2 -> 1, X
        // 2: 0 + 2 mod 2 = 0
        // 1, 2, 3 -> X, X, 3
        // 3: 0 + 2 mod 3 = 2
        // 1, 2, 3, 4 -> 1, X, X, X
        // 4: (2 + 2) mod 4 = 0
        // 5: (0 + 2) mod 5 = 2
        return rec + 1;
    }
};