class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
{
    vector<int> adjList[n + 1];
    vector<int> first(n + 1, 0);
    vector<int> second(n + 1, 0);
    int e = dislikes.size();

    for (int i = 0; i < e; i++)
    {
        adjList[dislikes[i][0]].push_back(dislikes[i][1]);
        adjList[dislikes[i][1]].push_back(dislikes[i][0]);  // Adding the reverse edge for an undirected graph
    }

    vector<int> visited(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;

        queue<pair<int, int>> helperQueue;
        helperQueue.push({i, 0});

        while (!helperQueue.empty())
        {
            pair<int, int> currentNode = helperQueue.front();
            helperQueue.pop();

            visited[currentNode.first] = 1;

            if (currentNode.second)
                first[currentNode.first]++;
            else
                second[currentNode.first]++;

            for (int j = 0; j < adjList[currentNode.first].size(); j++)
            {
                int neighbor = adjList[currentNode.first][j];

                if (!visited[neighbor])
                {
                    helperQueue.push({neighbor, !currentNode.second});
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (first[i] > 0 && second[i] > 0)
            return false;
    }

    return true;
}

};