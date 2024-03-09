class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> us;
        for(int i : nums1){
            us.insert(i);
        }
        int ans = INT_MAX;
        for(int i : nums2){
            if(us.find(i) != us.end()){
                if(ans > i){
                    ans = i;
                }
            }
        }
        return ans == INT_MAX ? -1 : ans; 
    }
};