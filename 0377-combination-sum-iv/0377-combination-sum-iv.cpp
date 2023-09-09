class Solution {
public:
    long long combinationSum4(vector<int>& nums, int target) {
    vector<long long> memo(target + 1, -1);
    memo[0] = 1;
    return calculateCombinations(nums, target, memo);
}

long long calculateCombinations(vector<int>& nums, int target, vector<long long>& memo) {
    if (memo[target] != -1) {
        return memo[target];
    }
    
    long long ans = 0;
    for (int num : nums) {
        if (target >= num) {
            ans += calculateCombinations(nums, target - num, memo);
        }
    }
    
    memo[target] = ans;
    return ans;
}

};