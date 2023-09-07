class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(3, 0));

    dp[0][0] = nums[0]; // Maximum product ending at index 0
    dp[0][1] = nums[0]; // Minimum product ending at index 0
    dp[0][2] = nums[0]; // Maximum product overall

    for (int i = 1; i < n; i++) {
        int num = nums[i];
        int max_ending_here = dp[i - 1][0] * num;
        int min_ending_here = dp[i - 1][1] * num;

        dp[i][0] = max(num, max(max_ending_here, min_ending_here));
        dp[i][1] = min(num, min(max_ending_here, min_ending_here));
        dp[i][2] = max(dp[i][0], dp[i - 1][2]);
    }

    return dp[n - 1][2];
}
};