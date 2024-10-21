class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        vector<int> helperVector (26, 0);
        unordered_map<int, int> helperMap;
        int ans = 0;int an1 = 0;
        for(int i = 0; i < n; i++){
            helperVector.assign(26, 0);
            helperMap.clear(); 
            for(int j = i; j < n; j++){ 
                
                helperVector[s[j]-'a']+=1;
                helperMap[helperVector[s[j]-'a']]+=1;
                if(helperMap[k] > 0){
                    
                    ans++;
                }
            }
        }
        return ans;
    }
};