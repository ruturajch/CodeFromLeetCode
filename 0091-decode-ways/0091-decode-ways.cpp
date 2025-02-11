class Solution {
public:
    int numDecodings(string s) {
    int n = s.size();
    if (n == 0 || s[0] == '0') return 0; // Handle edge cases
    
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1; // Initialize dp[1] as 1 if the first digit is not '0'

    for (int i = 2; i <= n; i++) {
        int oneDigit = stoi(s.substr(i - 1, 1));
        int twoDigits = stoi(s.substr(i - 2, 2));

        if (oneDigit >= 1 && oneDigit <= 9) {
            dp[i] += dp[i - 1];
        }
        if (twoDigits >= 10 && twoDigits <= 26) {
            dp[i] += dp[i - 2];
        }
    }

    return dp[n];
}
};