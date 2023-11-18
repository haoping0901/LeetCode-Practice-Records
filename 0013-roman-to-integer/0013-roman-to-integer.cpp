class Solution {
    int cnt = 0;
    string order = "IVXLCDM";
public:
    void add_value(const char& ch) {
        switch (ch) {
            case 'I':
                cnt += 1;
                break;
            case 'V':
                cnt += 5;
                break;
            case 'X':
                cnt += 10;
                break;
            case 'L':
                cnt += 50;
                break;
            case 'C':
                cnt += 100;
                break;
            case 'D':
                cnt += 500;
                break;
            case 'M':
                cnt += 1000;
                break;
        }
    }

    void check_combinations(const char& ch1, const char& ch2) {
        if ((ch1 == 'I') && (ch2 == 'V')) {
            cnt += 3;
        } else if ((ch1 == 'I') && (ch2 == 'X')) {
            cnt += 8;
        } else if ((ch1 == 'X') && (ch2 == 'L')) {
            cnt += 30;
        } else if ((ch1 == 'X') && (ch2 == 'C')) {
            cnt += 80;
        } else if ((ch1 == 'C') && (ch2 == 'D')) {
            cnt += 300;
        } else if ((ch1 == 'C') && (ch2 == 'M')) {
            cnt += 800;
        } else {
            add_value(ch2);
        }
    }

    int romanToInt(string s) {
        add_value(s[0]);
        for (int i=1; i<s.length(); i++) {
            check_combinations(s[i-1], s[i]);
        }

        return cnt;
    }
};