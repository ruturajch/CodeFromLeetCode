class Solution {
public:
    string makeGood(string s) {
        stack<char> helperStack;
        for(char it : s){
            if(helperStack.size() != 0){
                char top = helperStack.top();
                if(it - 'A' == top - 'a'){
                    helperStack.pop();
                }else if(top - 'A' == it - 'a'){
                    helperStack.pop();
                }else{
                    helperStack.push(it);
                }
            }else{
                helperStack.push(it);
            }
            
        }
        string ans = "";
        while(!helperStack.empty()){
            ans = string(1, helperStack.top()) + ans;
            helperStack.pop();
        }
        return ans;
    }
};