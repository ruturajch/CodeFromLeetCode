class Solution 
{
public:
    int minOperations(vector<int>& nums) 
    {
        int n,ans;
        n=nums.size();
        ans=n;

        sort(nums.begin(),nums.end()); 
        auto it=unique(nums.begin(),nums.end());
        nums.erase(it,nums.end());   

        int x;
        x=nums.size();

        for(int i=0;i<x;i++)
        {
            //int leftbound=nums[i]-n+1;
            int rightbound=nums[i]+n-1;

            //int leftsize=i-(lower_bound(nums.begin(),nums.begin()+i,leftbound)-nums.begin());
            int rightsize=(upper_bound(nums.begin()+i,nums.end(),rightbound)-nums.begin())-i;

            //ans=min(ans,min(n-leftsize-1,n-rightsize));
            ans=min(ans,n-rightsize);
        }

        return ans;
    }
};