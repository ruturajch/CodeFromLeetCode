class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        string s = to_string(x);
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            count += s[i] - '0';
        }
        if(x%count == 0){
            return count;
        }else{
            return -1; 
        }
    }
};