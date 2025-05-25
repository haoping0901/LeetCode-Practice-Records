class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        // 紀錄 T 與 F 區間中的以下訊:
            // 連續長度
            // 剩餘可翻轉答案的次數
        size_t tb = 0;
        size_t fb = 0;
        size_t end;
        unsigned tk = k;
        unsigned fk = k;
        int f_len = 0;
        int t_len = 0;

        for (end = 0; end < answerKey.length(); ++end) {
            if (answerKey[end] == 'T') {
                if (fk > 0) {
                    --fk;
                } else {
                    // 還一個翻轉 T 成 F 的額度
                    while (fb < end && answerKey[fb] != 'T') {
                        ++fb;
                    }
                    ++fb;
                }
            } else {
                if (tk > 0) {
                    --tk;
                } else {
                    // 還一個翻轉 F 成 T 的額度
                    while (tb < end && answerKey[tb] != 'F') {
                        ++tb;
                    }
                    ++tb;
                }
            }
            f_len = max(f_len, int(end - fb + 1));
            t_len = max(t_len, int(end - tb + 1));
        }

        // f_len = end - fb;
        // t_len = end - tb;

        return f_len > t_len ? f_len : t_len;
    }
};