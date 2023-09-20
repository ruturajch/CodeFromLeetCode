class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0; 
        int mxlen = 0; 
        int left = 0;
        int currsum = 0;
        for(auto num : nums) total += num;
        int target = total - x;
        
        if (target < 0) return -1;
        if (target == 0) return nums.size();



        for (int right = 0; right < nums.size(); right++) {
            currsum += nums[right];

            while (currsum > target) {
                currsum -= nums[left];
                left++;
            }

            if (currsum == target) {
                mxlen = max(mxlen, right - left + 1);
            }
        }

        return mxlen ? (nums.size() - mxlen) : -1;
    }
};