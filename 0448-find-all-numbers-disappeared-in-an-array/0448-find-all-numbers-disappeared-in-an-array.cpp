class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, int> um;
        for(int i = 0; i < nums.size(); i++){
            um[nums[i]] = 1;
        }        
        vector<int> ansVector;

        for(int i = 1; i <= nums.size(); i++){
            if(um[i] ==  0){
                ansVector.push_back(i);
            }
        }
        return ansVector;
    }
};