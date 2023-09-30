class Solution {
public:
    int back(int is1, int is2, int is3, string s1, string s2, string s3, vector<vector<vector<int>>>& dp)
{

    if (is1 == s1.size() || is2 == s2.size() || is3 == s3.size())
    {
        if (is1 == s1.size() && is2 == s2.size() && is3 == s3.size())
            return 1;
        else if (is1 == s1.size() && is2 == s2.size() && is3 != s3.size())
            return 0;
        else if (is3 == s3.size())
            return 0;
    }
    if(dp[is1][is2][is3] != -1){
        return dp[is1][is2][is3];
    }
    dp[is1][is2][is3] = false;
    if (is1 < s1.size() && s1[is1] == s3[is3])
        if (is2 == s2.size() || s2[is2] != s3[is3])
            dp[is1][is2][is3] = back(is1 + 1, is2, is3 + 1, s1, s2, s3, dp);

    if (is2 < s2.size() && s2[is2] == s3[is3])
        if (is1 == s1.size() || s1[is1] != s3[is3])
            dp[is1][is2][is3] = back(is1, is2 + 1, is3 + 1, s1, s2, s3, dp);

    if (is1 < s1.size() && s1[is1] == s3[is3] && is2 < s2.size() && s2[is2] == s3[is3])
        dp[is1][is2][is3] = back(is1, is2 + 1, is3 + 1, s1, s2, s3, dp) | back(is1 + 1, is2, is3 + 1, s1, s2, s3, dp);
    
    return dp[is1][is2][is3];
}
bool isInterleave(string s1, string s2, string s3)
{
    vector<vector<vector<int>>> dp(s1.size() + 1, vector<vector<int>>(s2.size()+ 1, vector<int>(s3.size()+1, -1)));

    return back(0, 0, 0, s1, s2, s3, dp) == 1 ? true : false;
}
};