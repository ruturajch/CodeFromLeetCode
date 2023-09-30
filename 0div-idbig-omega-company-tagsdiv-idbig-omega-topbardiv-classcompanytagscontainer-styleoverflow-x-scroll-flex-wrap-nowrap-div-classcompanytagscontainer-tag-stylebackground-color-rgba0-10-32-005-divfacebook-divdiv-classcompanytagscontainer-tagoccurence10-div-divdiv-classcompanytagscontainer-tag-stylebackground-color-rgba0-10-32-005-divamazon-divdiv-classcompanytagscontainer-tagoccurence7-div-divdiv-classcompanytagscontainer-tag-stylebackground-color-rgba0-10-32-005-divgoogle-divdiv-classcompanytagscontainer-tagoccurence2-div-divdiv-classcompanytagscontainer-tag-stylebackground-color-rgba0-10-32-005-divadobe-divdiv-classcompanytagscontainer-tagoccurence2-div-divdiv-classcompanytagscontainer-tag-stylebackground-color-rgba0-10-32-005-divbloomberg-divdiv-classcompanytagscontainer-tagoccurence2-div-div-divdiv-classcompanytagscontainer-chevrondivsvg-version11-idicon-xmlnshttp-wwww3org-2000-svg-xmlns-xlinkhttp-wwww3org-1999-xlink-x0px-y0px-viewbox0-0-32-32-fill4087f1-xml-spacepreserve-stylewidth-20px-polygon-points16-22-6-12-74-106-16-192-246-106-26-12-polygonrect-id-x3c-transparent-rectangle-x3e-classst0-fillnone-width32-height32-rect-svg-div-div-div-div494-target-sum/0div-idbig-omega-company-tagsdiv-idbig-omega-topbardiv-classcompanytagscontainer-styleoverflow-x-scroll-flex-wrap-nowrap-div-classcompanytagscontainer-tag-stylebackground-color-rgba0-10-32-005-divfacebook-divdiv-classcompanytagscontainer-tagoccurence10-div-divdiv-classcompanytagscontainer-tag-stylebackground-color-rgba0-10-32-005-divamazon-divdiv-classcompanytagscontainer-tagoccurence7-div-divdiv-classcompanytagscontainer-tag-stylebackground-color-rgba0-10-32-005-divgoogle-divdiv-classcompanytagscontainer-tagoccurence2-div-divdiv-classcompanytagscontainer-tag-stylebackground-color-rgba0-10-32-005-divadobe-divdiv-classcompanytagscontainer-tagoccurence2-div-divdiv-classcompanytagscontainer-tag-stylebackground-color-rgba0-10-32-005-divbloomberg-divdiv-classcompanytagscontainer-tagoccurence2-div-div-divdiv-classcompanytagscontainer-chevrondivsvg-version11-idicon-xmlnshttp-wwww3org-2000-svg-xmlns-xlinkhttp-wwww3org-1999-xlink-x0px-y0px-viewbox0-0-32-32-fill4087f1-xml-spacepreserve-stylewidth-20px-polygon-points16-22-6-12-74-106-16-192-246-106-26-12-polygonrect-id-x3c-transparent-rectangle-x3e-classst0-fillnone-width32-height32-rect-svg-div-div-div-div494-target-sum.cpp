class Solution {
public:
    int bac(int curSum, int l, vector<int>& nums, int target){
        if(l == nums.size() && curSum == target)
                return 1;  
        
        else if(l == nums.size())
                return 0;

        return bac(curSum + nums[l], l+1, nums, target) + bac(curSum - nums[l], l+1, nums, target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return bac(0, 0, nums, target);
    }
};