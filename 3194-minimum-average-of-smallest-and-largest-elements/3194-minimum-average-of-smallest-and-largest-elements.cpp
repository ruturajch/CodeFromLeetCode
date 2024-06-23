class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        double ans = 50;
        int it = 0;
        int n = nums.size();
        while(it < n/2){
            ans = ans < static_cast<double>(nums[it] + nums[n - it -1])/2 ? ans : static_cast<double>(nums[it] + nums[n - it -1])/2;
            it++;
        }
        return ans;
    }
};