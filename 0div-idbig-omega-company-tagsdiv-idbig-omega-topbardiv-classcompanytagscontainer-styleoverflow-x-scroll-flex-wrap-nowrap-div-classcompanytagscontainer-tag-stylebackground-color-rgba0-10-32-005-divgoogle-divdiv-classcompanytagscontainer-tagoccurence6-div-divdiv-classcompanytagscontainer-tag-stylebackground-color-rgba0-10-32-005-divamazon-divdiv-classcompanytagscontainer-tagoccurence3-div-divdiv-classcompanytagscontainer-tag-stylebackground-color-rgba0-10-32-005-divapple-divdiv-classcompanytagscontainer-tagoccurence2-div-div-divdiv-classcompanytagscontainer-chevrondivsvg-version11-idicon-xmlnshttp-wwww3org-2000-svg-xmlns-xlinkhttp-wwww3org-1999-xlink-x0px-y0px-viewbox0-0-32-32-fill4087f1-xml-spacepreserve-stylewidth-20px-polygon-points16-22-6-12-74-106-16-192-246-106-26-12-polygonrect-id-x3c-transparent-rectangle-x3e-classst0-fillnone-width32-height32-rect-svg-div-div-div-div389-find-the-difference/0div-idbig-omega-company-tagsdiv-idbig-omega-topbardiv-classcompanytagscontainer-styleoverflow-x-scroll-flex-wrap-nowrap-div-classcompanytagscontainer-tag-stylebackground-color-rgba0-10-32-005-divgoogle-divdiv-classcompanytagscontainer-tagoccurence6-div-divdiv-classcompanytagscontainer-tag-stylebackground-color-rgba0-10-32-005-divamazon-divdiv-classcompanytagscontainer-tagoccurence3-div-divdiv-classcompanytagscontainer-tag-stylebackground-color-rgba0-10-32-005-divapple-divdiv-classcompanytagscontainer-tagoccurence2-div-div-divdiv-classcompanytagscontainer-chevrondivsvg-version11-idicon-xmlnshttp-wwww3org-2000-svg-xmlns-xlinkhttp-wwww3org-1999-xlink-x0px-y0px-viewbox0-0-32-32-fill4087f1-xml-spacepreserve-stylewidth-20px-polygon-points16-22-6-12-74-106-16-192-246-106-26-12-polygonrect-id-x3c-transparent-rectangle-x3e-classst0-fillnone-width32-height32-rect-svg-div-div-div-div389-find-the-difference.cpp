class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> helperVector(26, 0);
        for(int i = 0; i < s.size(); i++){
            helperVector[s[i] - 'a']++;
        }
        for(int i = 0; i < t.size(); i++){
            helperVector[t[i] - 'a']--;
            if(helperVector[t[i] - 'a'] == -1){
                return t[i];
            }
        }
        return 'a';
    }
};