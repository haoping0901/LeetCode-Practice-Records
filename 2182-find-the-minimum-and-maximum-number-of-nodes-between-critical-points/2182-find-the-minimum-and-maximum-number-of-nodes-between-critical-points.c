/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    int *ret;
    int l_n;
    int m_n;
    int r_n, r_idx;
    int first_idx, last_idx;

    *returnSize = 2;
    ret = (int *)malloc(sizeof(int) * 2);
    ret[0] = -1;
    ret[1] = -1;

    l_n = head->val;
    head = head->next;
    m_n = head->val;
    head = head->next;
    r_idx = 2;
    first_idx = -1;

    while (head != NULL) {
        r_n = head->val;

        if (m_n < l_n && m_n < r_n) {
            // check min
            if (first_idx == -1) {
                first_idx = last_idx = r_idx;
            } else {
                if (ret[0] == -1)
                    ret[0] = ret[1] = r_idx - last_idx;
                if (r_idx - last_idx < ret[0])
                    ret[0] = r_idx - last_idx;
                ret[1] = r_idx - first_idx;
                last_idx = r_idx;
            }
        } else if (m_n > l_n && m_n > r_n) {
            // check max
            if (first_idx == -1) {
                first_idx = last_idx = r_idx;
            } else {
                if (ret[0] == -1)
                    ret[0] = ret[1] = r_idx - last_idx;
                if (r_idx - last_idx < ret[0])
                    ret[0] = r_idx - last_idx;
                ret[1] = r_idx - first_idx;
                last_idx = r_idx;
            }
        }
        l_n = m_n;
        m_n = r_n;
        ++r_idx;
        head = head->next;
    }

    return ret;
}