class Solution {
public:
    int ToInteger(const string& s) {
        int ret = 0;

        for (const char& c: s)
            ret |= (1 << (c - 'a'));

        return ret;
    }
    int similarPairs(vector<string>& words) {
        // Target: number of similar str
            // similar str: consist of the same char
        // str_ch: int to rec char of a str (bit 0 for 'a', bit 25 for 'z')
        // {str_ch, cnt}
        unordered_map<int, int> rec;
        int str_int, ret = 0;

        for (const string& s: words) {
            str_int = ToInteger(s);
            ret += rec[str_int]++;
        }

        return ret;
    }
};