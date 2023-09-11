class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ansVector;
        unordered_map<int, vector<int>> umap;
        for(int i = 0; i < groupSizes.size(); i++){
            umap[groupSizes[i]].push_back(i);
        }
        for(auto it: umap){
            int k = it.first;
            vector<int> temp;
            for(int i = 0; i < it.second.size(); i++){
                temp.push_back(it.second[i]);
                if(temp.size() == k){
                    ansVector.push_back(temp);
                    temp.clear();
                }
            }
        }
        return ansVector;        
    }
};