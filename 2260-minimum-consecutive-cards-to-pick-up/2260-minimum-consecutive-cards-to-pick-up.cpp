class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        // Input: arr of card val
            // Match: cards with same val
        // Target: min window that contains match card pair
        // {val, idx}
        unordered_map<int, int> rec;
        int ret = 200000;
        int i;

        for (i = 0; i < cards.size(); ++i) {
            if (rec[cards[i]] > 0)
                ret = min(ret, i - rec[cards[i]] + 2);
            
            rec[cards[i]] = i + 1;
        }

        return ret == 200000 ? -1 : ret;
    }
};