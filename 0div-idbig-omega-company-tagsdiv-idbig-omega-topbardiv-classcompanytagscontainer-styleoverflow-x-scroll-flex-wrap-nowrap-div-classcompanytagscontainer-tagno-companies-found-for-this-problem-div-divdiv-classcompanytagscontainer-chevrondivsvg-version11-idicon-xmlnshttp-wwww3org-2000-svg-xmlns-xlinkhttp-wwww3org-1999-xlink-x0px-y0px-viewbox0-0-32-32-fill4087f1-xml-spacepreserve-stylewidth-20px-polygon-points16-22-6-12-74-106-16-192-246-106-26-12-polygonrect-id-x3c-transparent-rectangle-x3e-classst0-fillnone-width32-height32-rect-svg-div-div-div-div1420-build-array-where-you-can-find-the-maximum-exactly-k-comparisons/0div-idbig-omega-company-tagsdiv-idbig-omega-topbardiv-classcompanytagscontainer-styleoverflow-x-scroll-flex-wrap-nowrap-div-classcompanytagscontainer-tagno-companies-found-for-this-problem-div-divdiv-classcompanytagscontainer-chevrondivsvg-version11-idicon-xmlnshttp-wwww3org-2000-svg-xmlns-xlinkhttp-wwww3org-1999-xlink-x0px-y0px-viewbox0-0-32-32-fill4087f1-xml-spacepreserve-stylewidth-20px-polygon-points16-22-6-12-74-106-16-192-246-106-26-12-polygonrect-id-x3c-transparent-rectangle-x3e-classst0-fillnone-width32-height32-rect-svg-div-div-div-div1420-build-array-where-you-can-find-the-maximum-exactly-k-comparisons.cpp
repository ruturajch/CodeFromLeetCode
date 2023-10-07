class Solution {
public:
    int N,M,K;
    int mod=1e9+7;
    int dp[51][51][101];
    int check(int idx,int srch,int maxx){
        if(idx==N){
            if(srch==K)return 1;
            return 0;
        }
        if(dp[idx][srch][maxx]!=-1)return dp[idx][srch][maxx];
        int res=0;
        for(int i=1;i<=M;i++){
            if(i>maxx){
                res=(res+check(idx+1,srch+1,i))%mod;
            }
            else{
                res=(res+check(idx+1,srch,maxx))%mod;
            }
        }
        return dp[idx][srch][maxx]=res%mod;
    }
    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        memset(dp,-1,sizeof(dp));
        return check(0,0,0);
    }
};