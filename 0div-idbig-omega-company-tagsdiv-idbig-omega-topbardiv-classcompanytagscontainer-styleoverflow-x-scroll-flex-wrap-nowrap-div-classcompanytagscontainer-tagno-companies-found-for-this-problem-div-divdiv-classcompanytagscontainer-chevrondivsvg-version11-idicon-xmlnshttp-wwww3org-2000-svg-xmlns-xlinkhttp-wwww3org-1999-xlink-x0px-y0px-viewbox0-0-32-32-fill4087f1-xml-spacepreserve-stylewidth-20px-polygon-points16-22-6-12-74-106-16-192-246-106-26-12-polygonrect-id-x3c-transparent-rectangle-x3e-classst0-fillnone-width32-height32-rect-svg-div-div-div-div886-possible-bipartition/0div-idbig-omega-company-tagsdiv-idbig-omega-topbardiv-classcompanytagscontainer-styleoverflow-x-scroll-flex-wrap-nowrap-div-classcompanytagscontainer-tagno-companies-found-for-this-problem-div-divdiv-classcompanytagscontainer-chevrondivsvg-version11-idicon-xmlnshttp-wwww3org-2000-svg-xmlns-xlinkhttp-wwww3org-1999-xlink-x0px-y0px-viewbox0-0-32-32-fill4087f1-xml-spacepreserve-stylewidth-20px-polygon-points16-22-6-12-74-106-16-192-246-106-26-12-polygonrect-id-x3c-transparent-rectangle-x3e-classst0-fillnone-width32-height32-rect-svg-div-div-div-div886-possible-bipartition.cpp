class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
{
    vector<vector<int>> adjList(n + 1);

    // Build adjacency list
    for (const auto &edge : dislikes)
    {
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }

    vector<int> group(n + 1, 0);
    queue<int> helperQueue;

    for (int i = 1; i <= n; ++i)
    {
        if (group[i] != 0)
            continue;

        helperQueue.push(i);
        group[i] = 1;

        while (!helperQueue.empty())
        {
            int currentNode = helperQueue.front();
            helperQueue.pop();

            for (int neighbor : adjList[currentNode])
            {
                if (group[neighbor] == 0)
                {
                    group[neighbor] = -group[currentNode];
                    helperQueue.push(neighbor);
                }
                else if (group[neighbor] == group[currentNode])
                {
                    // If the neighbor is in the same group, return false
                    return false;
                }
            }
        }
    }

    return true;
}

};