class Solution {
public:
    bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (auto i : nums)
    {
        sum += i;
    }
    if (sum % 2 == 1)
        return false;
    unordered_set<int> dp;
    dp.insert(0);
    dp.insert(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
        unordered_set<int> new_dp;
        for (int num : dp){
            new_dp.insert(num + nums[i]);   
        }
        dp.insert(new_dp.begin(), new_dp.end());
        
        if(dp.find(sum/2) != dp.end()){
            return true;
        }
    }
    return false;
}
};