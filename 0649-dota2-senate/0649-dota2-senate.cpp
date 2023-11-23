class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;
        int idx = senate.length();
        
        for (int i=0; i<senate.length(); i++) {
            if (senate.at(i) == 'R')
                radiant.push(i);
            else 
                dire.push(i);
        }

        while (!radiant.empty() && !dire.empty()) {
            if (radiant.front() > dire.front()) {
                dire.push(idx);
            } else {
                radiant.push(idx);
            }
            
            radiant.pop();
            dire.pop();
            idx++;
        }

        if (!radiant.empty())
            return "Radiant";
        else 
            return "Dire";
    }
};