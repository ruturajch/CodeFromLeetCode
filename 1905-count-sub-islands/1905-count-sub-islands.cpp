class Solution
{
private:
    bool dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int r, int c, int n, int m, vector<vector<int>> &helperVector)
    {
        if (r < 0 || c < 0 || r >= n || c >= m || grid2[r][c] == 0 || helperVector[r][c] == 1)
        {
            return true;
        }
        helperVector[r][c] = 1;
        bool ans = true;
        if (grid1[r][c] == 0)
        {
            ans = false;
        }
        int dim[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + dim[i][0];
            int ncol = c + dim[i][1];
            ans = ans & dfs(grid1, grid2, nrow, ncol, n, m, helperVector);
        }
        return ans;
    }

public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int n = grid1.size();
        int m = grid1[0].size();
        vector<vector<int>> helperVector(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (helperVector[i][j] == 0 && grid2[i][j] == 1 && dfs(grid1, grid2, i, j, n, m, helperVector))
                {
                    cout << i << j << endl;
                    ans++;
                }
            }
        }
        return ans;
    }
};