class Solution {
public:
    int hIndex(vector<int>& citations) {
        /* sort + n */
        sort(citations.begin(), citations.end());
        
        int h_index = 0;
        
        for (int i=citations.size()-1; i>=0; i--) {
            if (citations.at(i) >= h_index+1) {
                h_index++;
            } else {
                break;
            }
        }

        return h_index;
    }
};