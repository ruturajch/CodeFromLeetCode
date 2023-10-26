class Solution {
private:
    void back(string s, int l, string& helperString, vector<string>& ansVector, int count){
        if(l == s.size() && count == 0){
            ansVector.push_back(helperString);
        }else if(count == 0){
            return;
        }
        for(int i = 1; i <= 3 && (l + i - 1) < s.size(); i++){
            if(s[l] == '0' && i != 1)
                continue;
            string curString = s.substr(l, i);
            //cout << curString << endl;
            int cur = std::stoi(curString);
            if(cur <=255 && cur >= 0){
                if(helperString.size() != 0){
                    helperString += ".";
                    helperString += curString;
                    back(s, l+i, helperString, ansVector, count - 1);
                    for(int j = 0; j < i; j++){
                        helperString.pop_back();
                    }
                    helperString.pop_back();
                }else{
                    helperString += curString;
                    back(s, l+i, helperString, ansVector, count - 1);
                    for(int j = 0; j < i; j++){
                        helperString.pop_back();
                    }
                }
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ansVector;
        string helperString;
        back(s, 0, helperString, ansVector, 4);
        return ansVector;
    }
};