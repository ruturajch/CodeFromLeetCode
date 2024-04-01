class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        long long ansCount = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == !nums[i - 1]){
                dp[i] = dp[i-1];
                int n = i - dp[i-1] + 1;
                ansCount += n;
                //cout << n << "ruturaj" << endl;
            }else{
                dp[i] = i;
                ansCount++;
            }
            cout << ansCount << endl;
        }
        return ansCount;
    }
};