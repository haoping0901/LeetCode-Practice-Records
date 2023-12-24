class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        vector<int> ret(spells.size(), 0);
        for (int i=0; i<spells.size(); i++) {
            int left = 0, right = potions.size()-1;
            long long target = success/spells[i];
            if (success%spells[i] > 0) target++;

            while (left <= right) { 
                int pivot = (left+right) / 2;

                if (potions[pivot] < target) {
                    left = pivot + 1;
                } else if (potions[pivot] >= target) {
                    right = pivot - 1;
                } 
            }

            ret[i] = potions.size() - left;
        }
        
        return ret;
    }
};