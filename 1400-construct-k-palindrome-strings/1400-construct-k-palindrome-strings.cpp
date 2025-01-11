class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.size()){
            return false;
        }
        unordered_map<char, int> umap;
        for(char ch : s){
            umap[ch]++;
        }
        int oCount = 0;
        for(auto it : umap){
            if(it.second % 2 == 1){
                oCount++;
            }
        }
        if(oCount > k){
            return false;
        }
        return true;
    }
};