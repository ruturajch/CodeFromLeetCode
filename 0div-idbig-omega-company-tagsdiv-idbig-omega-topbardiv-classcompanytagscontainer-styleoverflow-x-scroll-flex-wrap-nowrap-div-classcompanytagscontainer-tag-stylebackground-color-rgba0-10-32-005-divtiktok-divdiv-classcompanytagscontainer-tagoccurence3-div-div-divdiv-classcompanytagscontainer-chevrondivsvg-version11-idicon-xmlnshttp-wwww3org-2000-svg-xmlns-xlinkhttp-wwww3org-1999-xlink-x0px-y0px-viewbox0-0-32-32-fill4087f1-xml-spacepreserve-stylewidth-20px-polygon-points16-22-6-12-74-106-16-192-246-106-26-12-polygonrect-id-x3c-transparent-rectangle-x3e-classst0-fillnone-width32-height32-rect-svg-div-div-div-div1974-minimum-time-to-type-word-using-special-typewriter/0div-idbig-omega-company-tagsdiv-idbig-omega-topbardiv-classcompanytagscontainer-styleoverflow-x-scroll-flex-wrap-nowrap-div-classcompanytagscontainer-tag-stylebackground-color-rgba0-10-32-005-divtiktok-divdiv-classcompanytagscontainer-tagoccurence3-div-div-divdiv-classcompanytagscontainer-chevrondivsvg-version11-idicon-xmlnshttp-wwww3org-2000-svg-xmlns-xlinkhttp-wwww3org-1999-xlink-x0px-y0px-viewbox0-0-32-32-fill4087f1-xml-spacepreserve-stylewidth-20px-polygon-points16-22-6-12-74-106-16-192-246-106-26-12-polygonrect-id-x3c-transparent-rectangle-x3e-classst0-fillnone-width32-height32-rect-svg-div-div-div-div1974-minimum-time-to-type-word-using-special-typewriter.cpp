class Solution {
public:
    int minTimeToType(string word) {
        int curPointer = 0;
        int len = word.size();
        int ans = 0;
        for(int i = 0; i < len; i++){
            int it = word[i] - 'a';
            int direct = abs(it - curPointer);
            
            int indirect = 0;
            if(it > curPointer ){
                indirect += (25 - it);
                indirect += (curPointer - 0);
                indirect ++;
            }else{
                indirect += (25 - curPointer);
                indirect += (it);
                indirect ++;
            }
            cout << direct << " " << indirect << endl;
            ans += min(direct, indirect);
            ans ++;
            curPointer = it;
        }  
        return ans;      
    }
};