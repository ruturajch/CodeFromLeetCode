class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int, int>> v;
        int n = arr.size();
        for(int i=0; i<n; i++){
            v.push_back({arr[i], i});
        }
        sort(v.begin(), v.end());
        int j = 1;
        int curele = 0;
        if(n > 0){
            curele = v[0].first;
        }
        vector<int> ans(n);
        for(int i = 0; i<n; i++){
            if(curele == v[i].first)
                ans[v[i].second] = j;
            else
                ans[v[i].second] = ++j;
            curele = v[i].first;
        }
        return ans;
    }
};