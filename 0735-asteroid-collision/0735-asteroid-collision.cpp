class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ret;

        for (const int& asteroid: asteroids) {
            if (ret.empty()) {
                ret.push_back(asteroid);
            } else if (asteroid < 0 && ret.back() > 0) {
                while (!ret.empty() && ret.back() > 0 && ret.back() < -asteroid) {
                    ret.pop_back();
                }

                if (ret.empty()) {
                    ret.push_back(asteroid);
                } else if (ret.back() == -asteroid) {
                    ret.pop_back();
                } else if (ret.back() < 0) {
                    ret.push_back(asteroid);
                }
            } else {
                ret.push_back(asteroid);
            }
        }

        return ret;
    }
};