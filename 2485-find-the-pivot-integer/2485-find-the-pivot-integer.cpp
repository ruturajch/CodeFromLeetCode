class Solution {
public:
    int pivotInteger(int n) {
        int sum = n * (n + 1)/2;
        int curSum = 0;
        for(int i = 1; i <= n; i++){
            curSum += i;
            if((curSum) == (sum - curSum + i)){
               return i; 
            }
        }

        return -1;
    }
};