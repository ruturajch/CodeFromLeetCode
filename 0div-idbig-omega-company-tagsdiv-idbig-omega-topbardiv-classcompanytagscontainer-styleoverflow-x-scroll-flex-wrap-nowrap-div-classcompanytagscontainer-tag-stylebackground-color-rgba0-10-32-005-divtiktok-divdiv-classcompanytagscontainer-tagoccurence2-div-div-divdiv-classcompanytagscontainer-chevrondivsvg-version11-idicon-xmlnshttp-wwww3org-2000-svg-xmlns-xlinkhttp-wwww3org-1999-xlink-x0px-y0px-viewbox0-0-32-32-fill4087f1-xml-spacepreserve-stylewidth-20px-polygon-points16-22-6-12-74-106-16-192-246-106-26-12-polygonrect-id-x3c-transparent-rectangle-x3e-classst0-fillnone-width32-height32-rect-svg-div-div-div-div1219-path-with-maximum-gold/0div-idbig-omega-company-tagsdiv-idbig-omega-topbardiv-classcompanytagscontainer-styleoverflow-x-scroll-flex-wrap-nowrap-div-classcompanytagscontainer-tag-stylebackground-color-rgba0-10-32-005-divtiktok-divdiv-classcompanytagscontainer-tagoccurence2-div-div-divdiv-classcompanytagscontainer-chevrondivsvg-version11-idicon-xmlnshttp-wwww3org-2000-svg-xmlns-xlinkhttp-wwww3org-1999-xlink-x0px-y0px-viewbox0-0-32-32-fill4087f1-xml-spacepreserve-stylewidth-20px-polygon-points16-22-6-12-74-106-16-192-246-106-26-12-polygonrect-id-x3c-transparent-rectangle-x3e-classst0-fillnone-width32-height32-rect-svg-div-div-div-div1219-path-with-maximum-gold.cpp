class Solution {
public:
    int returnMax(int l, int r, int n, int m, vector<vector<int>> &grid, vector<vector<bool>> &visited)
{
    if (l >= n || r >= m || l < 0 || r < 0 || grid[l][r] == 0 || visited[l][r])
    {
        return 0;
    }
    visited[l][r] = true;
    int ans = 0;
    int a = grid[l][r];
    int dim[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    for (int i = 0; i < 4; i++)
    {
        int ncol = l + dim[i][0];
        int nrow = r + dim[i][1];
        ans = max(ans, returnMax(ncol, nrow, n, m, grid, visited));
    }
    visited[l][r] = false;
    return a + ans;
}

int getMaximumGold(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans = max(ans, returnMax(i, j, m, n, grid, visited));
        }
    }
    return ans;
}

};