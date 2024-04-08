class Solution {
public:
    string minRemoveToMakeValid(string s) {
        set<int> toRemove;
        int n = s.size();
        stack<int> helperStack;

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                helperStack.push(i);
            }else if(s[i] == ')'){
                if(helperStack.empty()){
                    toRemove.insert(i);
                }else{
                    helperStack.pop();
                }
            }
        }
        while(!helperStack.empty()){
            toRemove.insert(helperStack.top());
            helperStack.pop();
        }
        string ans = "";
        for(int i = 0; i < n; i++){
            if(toRemove.find(i) == toRemove.end()){
                ans += string(1, s[i]);
            }
        }
        return ans;
    }
};