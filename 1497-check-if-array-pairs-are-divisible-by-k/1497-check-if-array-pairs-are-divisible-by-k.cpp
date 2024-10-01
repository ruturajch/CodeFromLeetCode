class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> um;
        
        // Count remainders
        for (auto it : arr) {
            int rem = (it % k + k) % k;  // Handle negative remainders
            um[rem]++;
        }

        // Check if pairs can be formed
        for (auto it : arr) {
            int rem = (it % k + k) % k;  // Handle negative remainders

            // If remainder is 0, check if count is even
            if (rem == 0) {
                if (um[rem] % 2 != 0) return false;
            } 
            // For other remainders, check if complement remainder has the same count
            else {
                if (um[rem] != um[k - rem]) return false;
            }
        }
        return true;
    }
};
