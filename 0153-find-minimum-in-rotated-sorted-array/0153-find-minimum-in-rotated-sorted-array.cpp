class Solution {
public:
    int findMin(vector<int>& nums) {
        int minele = nums[0];
        for(int i = 0;i < nums.size(); i++){
            minele = min(minele, nums[i]);
        }    
        return minele;
    }
};