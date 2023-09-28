class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        vector<int> evenArray;
        vector<int> oddArray;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] & 1)
                oddArray.push_back(nums[i]);
            else
                evenArray.push_back(nums[i]);
        }
        evenArray.insert(evenArray.end(), oddArray.begin(), oddArray.end());
        return evenArray;
    }
};