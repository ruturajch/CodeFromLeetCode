class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> um;
        int n = groupSizes.size();
        for(int i = 0; i < n; i++){
            um[groupSizes[i]].emplace_back(i);
        }
        for(auto pa : um){
            for(int i = 0; i < pa.second.size()/pa.first; i++){
                vector<int> temp;
                for(int j = 0; j < pa.first; j++){
                    temp.emplace_back(pa.second[j + i * pa.first]);
                }
                ans.emplace_back(temp);
            }

        }
        return ans;
    }

};