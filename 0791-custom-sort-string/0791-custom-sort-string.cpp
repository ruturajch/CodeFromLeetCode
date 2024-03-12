class Solution {
public:
    string customSortString(string order, string s) {
        unordered_set<char> helperMap;
        for(int i = 0; i < order.size(); i++){
            helperMap.insert(order[i]);
        }
        unordered_map<char, int> helperSet;
        for(int i = 0; i < s.size(); i++){
            if(helperMap.find(s[i]) != helperMap.end()){
                helperSet[s[i]]++;
                cout << helperSet[s[i]] << " " << s[i] << endl;
            }
        }
        string ans = "";
        for(int i = 0; i < order.size(); i++){
            if(helperSet.find(order[i]) != helperSet.end()){
                for(int j = 0; j < helperSet[order[i]]; j++){
                    ans += string(1, order[i]);
                }
            }
        }
        for(int i = 0; i < s.size(); i++){
            if(helperMap.find(s[i]) == helperMap.end()){
                ans += string(1, s[i]);
            }
        }
        return ans;
    }
};