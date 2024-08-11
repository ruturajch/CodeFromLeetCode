
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> helperUm;
        int ans = 0;
        int it = 0;
        for(int i=0; i<n; i++){
            if(helperUm.find(s[i]) != helperUm.end())
                 it = max(it, helperUm[s[i]] + 1);
            helperUm[s[i]] = i;
            ans = max(ans, i-it+1);
            cout << ans << " " << it << endl;
        }
        return ans;
    }
};