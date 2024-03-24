class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int len = 0;
        for(int i = 0; i < n; i++){
            unordered_map<char, int> um;
            for(int j = i; j < n; j++){
                if(um[s[j]] >= 2){
                    break;
                }
                um[s[j]]++;
                len = max(len, j - i + 1);
            }
        }
        return len;
    }
};