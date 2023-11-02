class Solution {
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        for (int i = 0; i < n; i++)
        {
            nums[i] = (nums[i] << 10) | nums[i + n];
        }

        int r = 2 * n - 1;
        int helperNum = pow(2, 10) - 1;
        for (int i = n - 1; i >= 0; i--)
        {
        
            nums[r--] = nums[i] & helperNum;
            nums[r--] = nums[i] >> 10;
        }
        return nums;
    }
};