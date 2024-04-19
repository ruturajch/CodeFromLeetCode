class Solution {
public:
   void bfs(vector<vector<int>>& helperVector, int k, int m, vector<int> adjList[]) {
    queue<int> q;
    q.push(k);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int i = cur / m;
        int j = cur % m;
        helperVector[i][j] = 1;
        for (int next : adjList[cur]) {
            int ni = next / m;
            int nj = next % m;
            if (helperVector[ni][nj] == 0) {
                q.push(next);
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    int sides[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vector<int> adjList[m * n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1') {
                for (int k = 0; k < 4; k++) {
                    int nrow = i + sides[k][0];
                    int ncol = j + sides[k][1];
                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == '1') {
                        adjList[i * m + j].emplace_back(nrow * m + ncol);
                    }
                }
            }
        }
    }
    vector<vector<int>> helperVector(n, vector<int>(m, 0));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (helperVector[i][j] == 0 && grid[i][j] == '1') {
                ans++;
                bfs(helperVector, i * m + j, m, adjList);
            }
        }
    }
    return ans;
}

};