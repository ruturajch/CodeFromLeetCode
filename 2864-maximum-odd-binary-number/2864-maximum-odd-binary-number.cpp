class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int CountOne = 0;
        for(char i : s){
            if(i == '1')
                CountOne++;
        }        
        cout << CountOne;
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(i < CountOne - 1)
                ans += '1';
            else   
                ans += '0'; 
            
        }
        ans[s.size() -1] = '1';
        return ans;

    }
};