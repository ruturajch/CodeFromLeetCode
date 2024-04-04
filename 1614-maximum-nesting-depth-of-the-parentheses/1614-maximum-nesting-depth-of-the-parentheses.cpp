class Solution {
public:
    int maxDepth(string s) {
        stack<char> helperStack;
        int ans = 0;
        for(char it : s){
            if(it == '('){
                helperStack.push(it);
            }else if(it == ')'){
                int temp = helperStack.size();
                ans = max(ans, temp);
                helperStack.pop();

            }
        }
        return ans;
    }
};