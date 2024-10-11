class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        // adding the index
        for(int i = 0; i < times.size(); i++){
            times[i].push_back(i);
        }
        // sort
        sort(times.begin(), times.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });
        priority_queue<int, vector<int>, greater<int>> helperOne;
        for (int i = 0; i < times.size(); i++) {
            helperOne.push(i);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> helperTwo;
        //cout << "ruturaj" << endl;
        // Output the
        for(int i = 0; i < times.size(); i++){
            while(!helperTwo.empty() &&helperTwo.top().first <= times[i][0]){
                helperOne.push(helperTwo.top().second);
                helperTwo.pop();
            }
            if(times[i][2] == targetFriend){
                return helperOne.top();
            }
            helperTwo.push({times[i][1],helperOne.top()});
            helperOne.pop();
        }

        return 0;
    }
};