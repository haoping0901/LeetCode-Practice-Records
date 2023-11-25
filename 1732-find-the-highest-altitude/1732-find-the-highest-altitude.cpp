class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int height=0, max=0;
        
        for (int i=0; i<gain.size(); i++) {
            height += gain.at(i);

            if (height > max)
                max = height;
        }

        return max;
    }
};