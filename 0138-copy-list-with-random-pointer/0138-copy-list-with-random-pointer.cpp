/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;

        Node *cur = head;

        // append a new node for all original nodes
        while (cur) {
            Node *new_node = new Node(cur->val);
            new_node->next = cur->next;
            cur->next = new_node;
            cur = new_node->next;
        }

        // set the random pointer of new nodes
        cur = head;
        while (cur) {
            if (cur->random) cur->next->random = cur->random->next;

            cur = cur->next->next;
        }

        // seperate the new and original nodes
        cur = head;
        Node *n_head = head->next;
        Node *n_cur = n_head;

        while (cur) {
            cur->next = cur->next->next;
            n_cur->next = n_cur->next ? n_cur->next->next : n_cur->next;

            cur = cur->next;
            n_cur = n_cur->next;
        }

        return n_head;
    }
};