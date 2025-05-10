class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // sliding window
        // 挑出 B 最多的區間中
        size_t l;
        size_t r;
        unsigned cnt = 0;
        unsigned max_len = 0;

        for (r = 0; r < k - 1; ++r) {
            if (blocks[r] == 'B')
                ++cnt;
        }

        for (l = 0; r < blocks.length(); ++l, ++r) {
            if (blocks[r] == 'B')
                ++cnt;
            
            max_len = max(max_len, cnt);

            if (blocks[l] == 'B')
                --cnt;
        }

        return k - max_len;
    }
};