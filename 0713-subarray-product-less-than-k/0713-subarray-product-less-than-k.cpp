class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if (k <= 1) return 0; // If k is less than or equal to 1, no subarray will satisfy the condition
        
        int prod = 1; // To keep track of product of elements in the current subarray
        int ansCount = 0; // Count of subarrays
        
        int left = 0; // Left pointer for sliding window
        
        for (int right = 0; right < n; right++) {
            prod *= nums[right]; // Include the current element in the product
            
            // Shrink the window if the product exceeds or equal to k
            while (prod >= k) {
                prod /= nums[left]; // Remove elements from the left end until the product is less than k
                left++;
            }
            
            // Add the count of subarrays ending at right pointer
            ansCount += right - left + 1;
        }
        
        return ansCount;
    }
};