class Solution {
public:
    vector<string> stringSequence(string target) {
        int n = target.size();
        vector<string> ans;
        for(int i = n-1; i >= 0; i--){
            for(int j = target[i] - 'a'; j >= 0; j--){
                string temp = target.substr(0, i) + string(1, 'a' + j);
                ans.insert(ans.begin(), temp);
            }
        }
        return ans;
    }
};