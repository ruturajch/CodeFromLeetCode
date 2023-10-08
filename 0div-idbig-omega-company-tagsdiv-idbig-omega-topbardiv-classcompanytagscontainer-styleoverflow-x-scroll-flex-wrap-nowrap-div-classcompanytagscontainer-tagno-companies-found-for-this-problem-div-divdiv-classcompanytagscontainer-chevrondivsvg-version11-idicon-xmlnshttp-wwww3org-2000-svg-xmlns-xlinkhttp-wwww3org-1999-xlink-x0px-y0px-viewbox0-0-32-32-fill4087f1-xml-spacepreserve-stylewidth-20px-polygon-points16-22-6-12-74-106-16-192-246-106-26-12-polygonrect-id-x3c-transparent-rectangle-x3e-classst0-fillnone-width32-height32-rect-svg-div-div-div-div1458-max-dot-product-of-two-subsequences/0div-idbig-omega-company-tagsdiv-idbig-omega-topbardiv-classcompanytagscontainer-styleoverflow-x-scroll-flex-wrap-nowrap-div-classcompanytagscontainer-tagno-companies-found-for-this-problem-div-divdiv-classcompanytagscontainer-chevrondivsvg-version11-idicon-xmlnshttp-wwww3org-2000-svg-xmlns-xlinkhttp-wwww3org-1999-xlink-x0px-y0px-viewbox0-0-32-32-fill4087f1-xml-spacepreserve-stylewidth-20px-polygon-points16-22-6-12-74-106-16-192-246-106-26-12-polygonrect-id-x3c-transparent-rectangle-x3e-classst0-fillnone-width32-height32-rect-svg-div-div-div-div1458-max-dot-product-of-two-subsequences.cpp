class Solution {
public:
     int maxDotProduct(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        // Initialize the dp array with very small values
        std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, INT_MIN));
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                // Update the dp value based on the transition formula
                dp[i][j] = std::max({dp[i][j], dp[i-1][j], dp[i][j-1]});
                dp[i][j] = std::max(dp[i][j], nums1[i-1] * nums2[j-1] + std::max(0, dp[i-1][j-1]));
            }
        }
        
        return dp[n][m];
    }
};