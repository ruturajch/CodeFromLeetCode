class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    stack<int> helperStack;
    int i = 0, j = 0;

    while (i < pushed.size() || j < popped.size()) {
        if (!helperStack.empty() && helperStack.top() == popped[j]) {
            helperStack.pop();
            j++;
        } else if (i < pushed.size()) {
            helperStack.push(pushed[i]);
            i++;
        } else {
            // If the stack is not empty and the top element doesn't match popped[j]
            // then the sequences are not valid
            return false;
        }
    }

    // If the loop completes without any issues, the sequences are valid
    return true;
}
};