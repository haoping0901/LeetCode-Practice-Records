class Solution {
public:
    int countOdds(int low, int high) {
        // Target: amount of odd number in range [low, high]
        // [odd, .. , odd]: => (h - l) / 2 + 1
        // [odd, .. , even] => (h - l) / 2 + 1
        // [even, .. , odd] => (h - l) / 2 + 1
        // [even, .. , even] => (h - 1) / 2
        if ((low & 0x1) == 0 && (high & 0x1) == 0)
            return (high - low) >> 1;
        else
            return ((high - low) >> 1) + 1;
    }
};