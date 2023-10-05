class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> um;
        for(int i : nums){
            um[i]++;
        }    
        int n = nums.size()/3;   
        vector<int> ansVector;
        for(auto i : um){
            if(i.second > n){
                ansVector.push_back(i.first);
            }
        }
        return ansVector;
    }
};