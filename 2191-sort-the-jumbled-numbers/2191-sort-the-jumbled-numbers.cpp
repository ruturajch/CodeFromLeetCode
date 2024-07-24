class Solution {
private:
    static bool check(pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> helperVector;
        for(int i = 0; i < n; i++){
            string temp = to_string(nums[i]);
            string trans = "";
            for(auto c : temp){
                trans += to_string(mapping[c - '0']);
            }
            int mapper = stoi(trans);
            helperVector.push_back({mapper, nums[i]});
        }
        sort(helperVector.begin(), helperVector.end(), check);
        vector<int> ans;
        for(int i = 0; i < n; i++){
            ans.push_back(helperVector[i].second);
        }
        return ans;
    }
};