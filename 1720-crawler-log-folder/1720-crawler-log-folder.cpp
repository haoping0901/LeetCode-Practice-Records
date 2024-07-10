class Solution {
public:
    int minOperations(vector<string>& logs) {
        // Check the substring before the '/' character in each string.
        // Add to the steps if the substring consists of letters and digits.
        // Decrease the steps by one if the substring contains 
        // two '.' characters.
        // Ignore substrings that consist of only a '.' character.
        int steps = 0;

        for (const string s: logs) {
            if (s.find("..") == 0 && steps > 0)
                --steps;
            else if (s.find("/") > 0 && s[0] != '.')
                ++steps;
        }

        return steps;
    }
};