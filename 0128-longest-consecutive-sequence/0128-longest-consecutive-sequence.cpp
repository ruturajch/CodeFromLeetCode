class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> helperSet(nums.begin(), nums.end());
        int length = 0;
        for(int it : nums){
            if(helperSet.find(it-1) == helperSet.end()){
                int tempLength = 0;
                while(helperSet.find(it) != helperSet.end()){
                    tempLength++;
                    it++;
                }
                length = max(length, tempLength);
            }
        }
        return length;
    }
};