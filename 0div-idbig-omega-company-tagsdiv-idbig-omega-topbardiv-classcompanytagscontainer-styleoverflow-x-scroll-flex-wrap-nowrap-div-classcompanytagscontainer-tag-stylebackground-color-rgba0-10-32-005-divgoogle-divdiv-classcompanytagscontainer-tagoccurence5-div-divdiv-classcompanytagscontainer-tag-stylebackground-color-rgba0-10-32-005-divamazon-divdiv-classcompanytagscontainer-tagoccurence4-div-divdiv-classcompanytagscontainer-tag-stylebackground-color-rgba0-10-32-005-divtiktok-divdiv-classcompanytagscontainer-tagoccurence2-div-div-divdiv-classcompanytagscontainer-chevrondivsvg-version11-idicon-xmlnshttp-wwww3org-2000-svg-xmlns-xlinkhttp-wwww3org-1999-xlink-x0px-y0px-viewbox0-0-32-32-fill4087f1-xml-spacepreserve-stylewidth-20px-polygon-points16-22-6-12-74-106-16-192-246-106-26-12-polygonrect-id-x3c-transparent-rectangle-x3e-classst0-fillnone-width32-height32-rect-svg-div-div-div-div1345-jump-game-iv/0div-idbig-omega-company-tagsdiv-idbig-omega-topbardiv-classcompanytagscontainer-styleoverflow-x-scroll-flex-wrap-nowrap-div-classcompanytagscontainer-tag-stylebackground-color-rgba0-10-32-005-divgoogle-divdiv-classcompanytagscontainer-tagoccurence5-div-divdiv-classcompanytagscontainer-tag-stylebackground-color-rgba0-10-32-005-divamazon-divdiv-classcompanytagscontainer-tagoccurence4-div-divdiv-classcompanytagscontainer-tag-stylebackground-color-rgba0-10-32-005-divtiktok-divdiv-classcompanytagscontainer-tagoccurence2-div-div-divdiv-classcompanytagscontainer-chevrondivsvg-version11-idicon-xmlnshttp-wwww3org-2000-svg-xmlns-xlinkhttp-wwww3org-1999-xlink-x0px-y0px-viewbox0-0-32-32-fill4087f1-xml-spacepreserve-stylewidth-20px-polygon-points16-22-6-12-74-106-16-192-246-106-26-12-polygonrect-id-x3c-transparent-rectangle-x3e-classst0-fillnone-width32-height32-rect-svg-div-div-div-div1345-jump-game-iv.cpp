#pragma GCC optimize("Ofast")
#pragma GCC target("tune=native")
static int fast_io = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
class Solution {
public:
    unordered_map<int,vector<int>> mp; //key: -23(arr value), val: {1,2} (location)
    queue<int> q;
    vector<int> dp;
    
    int minJumps(vector<int>& arr) {

        dp = vector<int> (arr.size(), -1);
        for(int i = 0; i<arr.size(); ++i){
            mp[arr[i]].push_back(i);
        }
        
        //DP Initilization
        q.push(0);
        dp[0] = 0;

        //DP traverse
        while(!q.empty()){
            int i = q.front();
            q.pop();
            if(i==arr.size()-1) return dp.back();

            if(i>0){
                check(arr,i,i-1);
            }

            check(arr,i,i+1);

            for(int j: mp[arr[i]]){
                check(arr,i,j);
            }
            mp[arr[i]].clear();
        }
        return dp.back();
    }
    inline void check(const vector<int>& arr, const int& i, const int& j){
                if(dp[j]==-1){ 
                    q.push(j);
                    dp[j] = dp[i]+1;
                }
    }
};