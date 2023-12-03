class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> repeat1, repeat2;
        unordered_map<int, int> cnt1, cnt2;

        // record the amount of the repeat times of each character
        for (const char& word: word1) {
            if (repeat1.count(word) == 0) {
                repeat1[word] = 1;
            } else {
                repeat1[word]++;
            }
        }
        for (const char& word: word2) {
            if (repeat2.count(word) == 0) {
                repeat2[word] = 1;
            } else {
                repeat2[word]++;
            }
        }

        // check whether a string contains the character another doesn't contain
        for (const auto& [key, value]: repeat1) {
            if (repeat2.count(key) == 0) {
                return false;
            }
        }

        // record the amount of each repeat time
        for (const auto& [key, value]: repeat1) {
            if (cnt1.count(value) == 0) {
                cnt1[value] = 1;
            } else {
                cnt1[value]++;
            }
        }
        for (const auto& [key, value]: repeat2) {
            if (cnt2.count(value) == 0) {
                cnt2[value] = 1;
            } else {
                cnt2[value]++;
            }
        }

        // compare whether there exists the different between the repeat time
        for (const auto& [key, value]: cnt1) {
            if (cnt2.count(key) == 0) {
                return false;
            } else if (cnt2[key] != value) {
                return false;
            }
        }

        return true;
    }
};