class Solution {
public:
    int minLength(string s) {
        stack<char> helperStack;
        for(char i : s){
            if((i == 'B' && !helperStack.empty() && helperStack.top() == 'A') 
                || (i == 'D' && !helperStack.empty() && helperStack.top() == 'C')){
                helperStack.pop();
            }else{
                helperStack.push(i);
            }
        }

        return helperStack.size();
    }
};