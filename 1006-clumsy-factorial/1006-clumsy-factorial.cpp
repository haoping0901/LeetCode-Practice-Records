class Solution {
public:
    int clumsy(int n) {
        int ans = 0, hold = n, op = 0;

        // need to flush the val when encountering '-' operator
        while (--n > 0) {
            switch (op) {
            case 0: // *
                hold *= n;
                break;
            case 1: // /
                hold /= n;
                break;
            case 2: // +
                hold += n;
                break;
            case 3: // -
                ans += hold;
                hold = -n;
                break;
            default:
                break;
            }
            op = (op + 1) & 0x3;
        }

        return ans + hold;
    }
};