class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> helperVector(2 * n);
        for(int i = 0; i < n; i++){
            helperVector[i] = nums[i];
            helperVector[i + n] = nums[i];
        }
        return helperVector;
    }
};