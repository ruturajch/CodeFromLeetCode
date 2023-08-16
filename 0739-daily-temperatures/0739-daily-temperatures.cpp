class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<pair<int,int>> ansStack;
        ansStack.push(make_pair(temperatures[0], 0));

        for(int i = 1; i < temperatures.size(); i++){
            while(!ansStack.empty() && ansStack.top().first < temperatures[i]){
                ans[ansStack.top().second] = i - ansStack.top().second;
                ansStack.pop();
            }
            ansStack.push(make_pair(temperatures[i], i));
        }

        return ans;        
    }
};