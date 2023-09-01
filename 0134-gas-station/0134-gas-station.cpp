class Solution {
public:
   int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        vector<int> dp(n, 0);
        int sum = 0;
        for(int i = 0; i < n; i++){
            dp[i] = gas[i]- cost[i];
            sum += dp[i];
        }
        if(sum < 0){
            return -1;
        }

        int index = n - 1;
        int curr = 0;
        sum = INT_MIN;
        for(int i = n - 1; i >= 0; i--){
            curr += dp[i];
            if(sum < curr){
                sum = curr;
                index = i;
            }
        }
        return index;
    }
};