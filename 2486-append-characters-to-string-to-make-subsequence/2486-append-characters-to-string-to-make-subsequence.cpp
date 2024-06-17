class Solution {
public:
    int appendCharacters(string s, string t) {
        int sit = 0;
        int tit = 0;
        while(sit < s.size() && tit < t.size()){
            if(s[sit] == t[tit]){
                sit++;
                tit++;
            }else{
                sit++;
            }
            
        }
        return (t.size() - tit);
    }
};