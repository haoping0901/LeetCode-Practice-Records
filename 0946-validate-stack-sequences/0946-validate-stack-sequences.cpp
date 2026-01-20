class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        deque<int> stack;

        // Iterate pushed from the start
            // while !stack.empty && stack.top == popped[j]
                // ++j

            // if pushed[i] == popped[j]
                // skip pushed[i]
                // ++j
            // if pushed[i] != popped[j]
                // push pushed[i] to a stack
        int j = 0, n = popped.size();
        for (const int p: pushed) {
            if (p == popped[j])
                ++j;
            else
                stack.push_back(p);

            while (!stack.empty() && j < n && stack.back() == popped[j]) {
                stack.pop_back();
                ++j;
            }
        }

        return stack.empty();
    }
};