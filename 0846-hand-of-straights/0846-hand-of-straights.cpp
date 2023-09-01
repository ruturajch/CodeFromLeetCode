class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        sort(hand.begin(), hand.end());

        int n = hand.size();
        if(n % groupSize > 0)return false;
        int k = n/groupSize;
        vector<int> dp(n, 0);
        for(int i = 0; i < k ;i++){
            int k = -1;
            int count = 0;
            for(int j = 0; j < n; j++){
                if(k == -1 && dp[j] == 0){
                    dp[j] = i+1;
                    k = hand[j];
                    count++;
                }
                else if(dp[j] == 0 && !(hand[j] == k || hand[j] == k + 1)){

                    return false;

                }
                else if(dp[j] == 0 && hand[j] == k+1){
                    k = k + 1;
                    dp[j] = i+1;
                    count++;
                }
                if(count == groupSize) break;
            }
            if(count < groupSize) return false;
        }
        return true;
    }

};