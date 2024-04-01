class Solution {
public:
    int lengthOfLastWord(string s) {
        int answer = 0;
        bool bit = false;
        for(int i = s.size() - 1; i >= 0 ;i--){
            if(s[i] == ' ' && bit){
                return answer;
            }else if(s[i] != ' ' ){
                bit = true;
                answer++;
            }
        }
        return answer;
    }
};