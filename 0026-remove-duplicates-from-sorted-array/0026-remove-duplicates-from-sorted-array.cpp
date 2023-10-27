class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> um;
        int ansCount = 0;
        int n = nums.size();
        int cur = -101;
        int index = 0;
        for(int i = 0; i < n; i++){
            if(cur != nums[i]){
                nums[index++] = nums[i];
                cur = nums[i];
                ansCount++;
            }
        }
        return ansCount;
    }
};