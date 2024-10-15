class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        int lone = 0; 
        int count = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                lone += (i - count);
                count++;
            }
        }
        count = 0;
        long long rone = 0;
        for(int i = 0; i < n; i++){
            if(s[n - i - 1] == '1'){
                rone += (i - count);
                count++;
            }
        }
        return rone;
    }
};