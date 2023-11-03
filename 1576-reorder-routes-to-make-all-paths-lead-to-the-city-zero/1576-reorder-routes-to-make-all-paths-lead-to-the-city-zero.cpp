class Solution
{
public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<int> neighbors[n];
        unordered_set<int> adjList[n];
        for (int i = 0; i < connections.size(); i++)
        {
            neighbors[connections[i][0]].emplace_back(connections[i][1]);
            neighbors[connections[i][1]].emplace_back(connections[i][0]);
            adjList[connections[i][0]].insert(connections[i][1]);
        }
        int ans = 0;
        queue<int> helperQueue;
        helperQueue.push(0);
        vector<int> visited(n, 0);
        while (!helperQueue.empty())
        {
            int cur = helperQueue.front();
            if(visited[cur] == 1)
                continue;
            visited[cur] = 1;
            helperQueue.pop();
            int neighborsCount = neighbors[cur].size();
            //cout << cur << neighborsCount << endl;
            for (int i = 0; i < neighborsCount; i++)
            {
                //cout << adjList[neighbors[cur][i]].size() << " " << neighbors[cur][i] << " " << cur << endl;
                if (visited[neighbors[cur][i]] == 0 && adjList[neighbors[cur][i]].find(cur) == adjList[neighbors[cur][i]].end())
                {
                    cout << cur << neighbors[cur][i] << endl;
                    ans++;
                }
                if (visited[neighbors[cur][i]] == 0)
                {
                    helperQueue.push(neighbors[cur][i]);
                }
            }
        }
        return ans;
    }
};