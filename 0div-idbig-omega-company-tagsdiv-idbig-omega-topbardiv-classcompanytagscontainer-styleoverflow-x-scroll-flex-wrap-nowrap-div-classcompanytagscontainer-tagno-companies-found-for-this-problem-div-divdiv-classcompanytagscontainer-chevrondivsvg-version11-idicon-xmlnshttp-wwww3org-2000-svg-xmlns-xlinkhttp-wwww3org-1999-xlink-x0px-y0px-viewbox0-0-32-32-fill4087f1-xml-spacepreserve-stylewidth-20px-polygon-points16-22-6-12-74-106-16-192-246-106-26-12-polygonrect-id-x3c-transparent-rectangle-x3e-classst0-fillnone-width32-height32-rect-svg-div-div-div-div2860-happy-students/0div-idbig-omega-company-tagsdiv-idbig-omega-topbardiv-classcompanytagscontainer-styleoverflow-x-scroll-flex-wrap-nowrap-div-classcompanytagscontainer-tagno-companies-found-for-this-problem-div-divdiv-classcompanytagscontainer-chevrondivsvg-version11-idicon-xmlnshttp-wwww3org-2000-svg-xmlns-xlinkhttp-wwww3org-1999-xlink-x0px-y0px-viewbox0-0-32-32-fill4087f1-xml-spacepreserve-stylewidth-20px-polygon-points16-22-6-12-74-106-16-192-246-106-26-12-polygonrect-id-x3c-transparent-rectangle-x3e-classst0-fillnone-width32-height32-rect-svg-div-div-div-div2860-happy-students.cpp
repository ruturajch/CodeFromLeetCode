class Solution {
public:
    int countWays(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int selected=0;
        sort(nums.begin(),nums.end());
        if(nums[0]!=0)cnt=1;
        for(int i=0;i<n;++i){
            selected++;
            if(i+1>nums[i]){
                if(i+1<n && i+1<nums[i+1])cnt++;
                else if(i+1==n)cnt++;
            }
        }
        return cnt;
    }
};