/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int gcd(int m, int n)
{
    if (n == 0)
        return m;
    else
        return gcd(n, m % n);
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
    struct ListNode *cur = head;
    struct ListNode *new_node = NULL;

    while (cur && cur->next) {
        new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
        new_node->val = gcd(cur->val, cur->next->val);
        new_node->next = cur->next;
        cur->next = new_node;
        cur = new_node->next;
    }

    return head;
}