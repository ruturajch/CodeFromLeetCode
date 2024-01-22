class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> us;
        vector<int> ansVector;
        for(int i = 0; i < n; i++){
            if(us.find(nums[i]) != us.end()){
                ansVector.push_back(nums[i]);
            }   
            us.insert(nums[i]);
        }
        for(int i = 1; i <= n; i++){
            if(us.find(i) == us.end()){
                ansVector.push_back(i);
                return ansVector;
            }
        }
        return ansVector;
    }
};