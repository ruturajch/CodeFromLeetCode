class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ansCount = 1;
        int it = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == !nums[i - 1]){
                ansCount += i - it + 1;
            }else{
                it = i;
                ansCount++;
            }
        }
        return ansCount;
    }
};