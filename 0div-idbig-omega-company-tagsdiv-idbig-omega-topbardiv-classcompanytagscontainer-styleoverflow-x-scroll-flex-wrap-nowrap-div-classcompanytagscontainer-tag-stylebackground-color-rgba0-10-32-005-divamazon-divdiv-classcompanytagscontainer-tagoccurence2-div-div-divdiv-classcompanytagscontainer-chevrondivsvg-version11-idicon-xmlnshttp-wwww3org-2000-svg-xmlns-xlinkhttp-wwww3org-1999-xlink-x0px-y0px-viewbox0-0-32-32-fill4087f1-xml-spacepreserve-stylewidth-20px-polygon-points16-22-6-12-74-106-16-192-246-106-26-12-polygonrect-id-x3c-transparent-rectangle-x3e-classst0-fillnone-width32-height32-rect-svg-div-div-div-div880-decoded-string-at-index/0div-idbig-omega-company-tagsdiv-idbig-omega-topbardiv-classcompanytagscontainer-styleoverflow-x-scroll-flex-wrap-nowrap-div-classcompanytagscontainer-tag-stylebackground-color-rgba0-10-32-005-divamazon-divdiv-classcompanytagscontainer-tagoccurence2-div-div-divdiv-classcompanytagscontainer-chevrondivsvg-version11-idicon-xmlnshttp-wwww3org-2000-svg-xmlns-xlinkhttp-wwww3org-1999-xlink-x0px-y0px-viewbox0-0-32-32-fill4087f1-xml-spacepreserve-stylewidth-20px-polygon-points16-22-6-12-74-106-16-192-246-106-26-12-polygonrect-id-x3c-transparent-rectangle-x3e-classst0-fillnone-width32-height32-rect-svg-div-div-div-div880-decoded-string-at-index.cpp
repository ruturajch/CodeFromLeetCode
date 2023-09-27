class Solution {
public:
    string decodeAtIndex(string s, int k) {
    long long int n = s.length();
    long long int i = 0;
    long long int count = 0;
    while(i < n){
        if(isdigit(s[i])){
            count = count * (s[i] - '0');
        }
        else{
            count++;
        }
        if(count >= k){
            break;
        }
        i++;
    }
    while(i >= 0){
        if(isdigit(s[i])){
            count = count / (s[i] - '0');
            k = k % count;
            if(k == 0){
                k = count;
            }
        }
        else{
            if(k == count){
                return string(1, s[i]);
            }
            count--;
        }
        i--;
    }
    return "";        
}
};