class Solution {
private:
    int dfs(vector<pair<int, int>> adjList[], int tot, int l, int signalSpeed, vector<bool>& visited) {
        visited[l] = true;

        int ans = 0;
        if (tot % signalSpeed == 0) {
            ans++;
        }

        for (int i = 0; i < adjList[l].size(); i++) {
            if (!visited[adjList[l][i].first]) {
                ans += dfs(adjList, tot + adjList[l][i].second, adjList[l][i].first, signalSpeed, visited);
            }
        }

        return ans;
    }

    int cal(const vector<int>& tempVector) {
        int ans = 0;
        for(int i = 0; i < tempVector.size(); i++){
            for(int j = i + 1; j < tempVector.size(); j++){
                ans += (tempVector[i] * tempVector[j]);
            }
        }
        return ans;
    }

public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = 0;
        
        for (auto it : edges) {
            n = max(n, max(it[0], it[1]));
        }

        n++;
        vector<int> helperVector(n, 0);
        vector<pair<int, int>> adjList[n];

        for (auto it : edges) {
            adjList[it[0]].push_back({it[1], it[2]});
            adjList[it[1]].push_back({it[0], it[2]});
        }

        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            vector<int> tempVector;
            visited[i] = true;
            for(auto it : adjList[i]){
                tempVector.push_back(dfs(adjList, it.second, it.first, signalSpeed, visited));
            }
            helperVector[i] = cal(tempVector);
            //cout << "a" << endl;
        }
        return helperVector;
    }
};