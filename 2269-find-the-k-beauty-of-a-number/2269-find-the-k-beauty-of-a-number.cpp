class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int n = s.length();
        int ret = 0;

        for (int i = 0; i + k - 1 < n; ++i) {
            int divisor = stoi(s.substr(i, k));

            if (divisor != 0 && num % divisor == 0)
                ++ret;
        }

        return ret;
    }
};