class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int totalSum = 0;
        
        // Calculate the total sum of the array
        for (int num : nums) {
            totalSum = (totalSum + num) % p;
        }
        
        // If total sum is already divisible by p, no need to remove any subarray
        if (totalSum == 0) return 0;
        
        // We need to remove a subarray such that the sum of the rest of the array is divisible by p.
        // That means we are looking for a subarray with sum equal to totalSum % p.
        int targetMod = totalSum;
        
        unordered_map<int, int> modIndex;  // Stores mod value and the latest index
        modIndex[0] = -1;  // For edge cases where prefix mod is directly equal to targetMod
        
        int prefixSum = 0;
        int result = n;  // Initialize result with max value (n)
        
        for (int i = 0; i < n; ++i) {
            prefixSum = (prefixSum + nums[i]) % p;
            
            // We want to find a subarray with sum % p == targetMod
            int neededMod = (prefixSum - targetMod + p) % p;
            
            if (modIndex.find(neededMod) != modIndex.end()) {
                result = min(result, i - modIndex[neededMod]);
            }
            
            // Update the map with the current prefix sum mod
            modIndex[prefixSum] = i;
        }
        
        return result == n ? -1 : result;
    }
};