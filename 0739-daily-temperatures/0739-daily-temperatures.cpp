class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int days = temperatures.size();
        vector<int> ret(days, 0);

        for (int i=days-1; i>0; i--) {
            if (temperatures[i-1] >= temperatures[i]) {
                ret[i-1]++;
                int idx = i;
                while (temperatures[idx] <= temperatures[i-1] && ret[idx] > 0) {
                    ret[i-1] += ret[idx];
                    idx += ret[idx];
                }

                // case there's no warmer temperature
                if (temperatures[idx] <= temperatures[i-1]) ret[i-1] = 0;
            } else {
                ret[i-1] = 1;
            }
        }

        return ret;
    }
};