class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ansVector(n, 0);
        int p = 0;
        int e = 0;
        int i = 0;
        while(p < n || e < n){
            while(p < n && nums[p] < 0){
                p++;
            }
            while(e < n && nums[e] > 0){
                e++;
            }
            if(p < n){
                ansVector[i++] = nums[p++];
            }
            if(e < n){
                ansVector[i++] = nums[e++];
            }
        }
        return ansVector;
    }
};