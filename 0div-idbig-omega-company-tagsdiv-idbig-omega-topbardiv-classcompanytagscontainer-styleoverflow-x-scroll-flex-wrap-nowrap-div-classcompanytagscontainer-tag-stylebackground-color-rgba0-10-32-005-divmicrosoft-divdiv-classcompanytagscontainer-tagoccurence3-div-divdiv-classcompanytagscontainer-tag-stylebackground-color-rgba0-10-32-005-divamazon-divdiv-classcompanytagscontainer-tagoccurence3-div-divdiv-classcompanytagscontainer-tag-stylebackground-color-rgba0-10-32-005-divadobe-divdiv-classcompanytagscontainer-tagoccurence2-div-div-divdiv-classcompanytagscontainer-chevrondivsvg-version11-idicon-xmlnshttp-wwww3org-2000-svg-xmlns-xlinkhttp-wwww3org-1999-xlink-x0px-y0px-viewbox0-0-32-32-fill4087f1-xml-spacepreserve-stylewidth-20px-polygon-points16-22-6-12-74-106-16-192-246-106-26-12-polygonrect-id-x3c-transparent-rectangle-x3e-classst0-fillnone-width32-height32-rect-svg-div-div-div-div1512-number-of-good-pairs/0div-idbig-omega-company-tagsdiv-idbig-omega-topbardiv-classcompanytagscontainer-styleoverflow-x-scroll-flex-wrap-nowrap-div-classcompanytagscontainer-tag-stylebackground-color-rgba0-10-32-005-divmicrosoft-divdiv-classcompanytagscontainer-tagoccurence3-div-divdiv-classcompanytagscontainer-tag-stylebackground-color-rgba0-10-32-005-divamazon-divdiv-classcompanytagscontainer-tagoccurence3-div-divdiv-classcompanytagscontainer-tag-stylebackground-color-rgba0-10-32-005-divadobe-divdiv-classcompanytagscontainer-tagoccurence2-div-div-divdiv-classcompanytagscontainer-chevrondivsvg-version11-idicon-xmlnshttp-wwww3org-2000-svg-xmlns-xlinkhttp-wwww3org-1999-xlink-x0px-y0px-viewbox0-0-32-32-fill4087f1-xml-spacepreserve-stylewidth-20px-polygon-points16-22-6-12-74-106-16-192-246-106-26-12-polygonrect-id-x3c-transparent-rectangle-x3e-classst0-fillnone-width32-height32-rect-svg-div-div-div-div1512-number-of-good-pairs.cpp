class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> helperVector(101, 0);
        for(int i  = 0; i < nums.size(); i++){
            helperVector[nums[i]]++;
        }
        int ans = 0;
        for(int i = 0; i < 101; i++){
            //cout << nums[i] << endl;
            ans += (helperVector[i]  - 1)*(helperVector[i])/2;
        }
        return ans;
    }
};