class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> helperVector;
        for(int i = 0; i < nums.size(); i++)
        {   
            for(auto it : nums[i]){
                helperVector.push_back({it, i});
            }
        }
        sort(helperVector.begin(), helperVector.end());
        
        set<int> expectedSet;
        for(int i = 0; i < nums.size(); i++){
            expectedSet.insert(i);
        }

        int l = 0;
        int r = 0;
        int ans = helperVector[helperVector.size()-1].first - helperVector[0].first;
        
        vector<int> ansVec;
        ansVec.push_back(helperVector[0].first);
        ansVec.push_back(helperVector[helperVector.size()-1].first);
        unordered_map<int, int> helperMap;
        while(r < helperVector.size()){
            helperMap[helperVector[r].second]++;
            expectedSet.erase(helperVector[r].second);
            while(expectedSet.empty()){
                if((helperVector[r].first-helperVector[l].first) < ans){
                    ansVec[0] = helperVector[l].first;
                    ansVec[1] = helperVector[r].first;
                    ans = helperVector[r].first-helperVector[l].first;
                }
                helperMap[helperVector[l].second]--;
                if(helperMap[helperVector[l].second] == 0){
                    expectedSet.insert(helperVector[l].second);
                }
                l++;
            }
            r++;
        }
        return ansVec;
    }
};