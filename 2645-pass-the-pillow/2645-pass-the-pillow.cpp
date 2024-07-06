class Solution {
public:
    int passThePillow(int n, int time) {
        // calculate number of traversion 
        // infer the position by checking number of traversion (%2)
        int traverse_times = time / (n - 1);
        bool from_end = traverse_times & 0x1;

        if (from_end)
            return n - time % (n-1);
        else 
            return time % (n-1) + 1;
    }
};