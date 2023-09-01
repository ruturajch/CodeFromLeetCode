class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        for(int i = 1; i < n; i++){
            int ans = INT_MAX;
            for(int j = 0; j < i; j++){
                if((i - j) <= nums[j])
                    ans = min(dp[j] + 1, ans);
            }
            dp[i] = ans;
        }
        return dp[n - 1];
    }
};