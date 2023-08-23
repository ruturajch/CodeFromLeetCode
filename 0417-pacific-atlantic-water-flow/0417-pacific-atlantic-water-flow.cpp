class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> pacific(rows, vector<int>(cols, 0));
        vector<vector<int>> atlantic(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; ++i) {
            dfs(matrix, pacific, i, 0);
            dfs(matrix, atlantic, i, cols - 1);
        }

        for (int j = 0; j < cols; ++j) {
            dfs(matrix, pacific, 0, j);
            dfs(matrix, atlantic, rows - 1, j);
        }

        vector<vector<int>> result;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

private:
    void dfs(const vector<vector<int>>& matrix, vector<vector<int>>& ocean, int i, int j) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || ocean[i][j]) {
            return;
        }

        ocean[i][j] = 1;

        static const vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (const auto& dir : directions) {
            int ni = i + dir.first;
            int nj = j + dir.second;

            if (ni >= 0 && ni < matrix.size() && nj >= 0 && nj < matrix[0].size() && matrix[ni][nj] >= matrix[i][j]) {
                dfs(matrix, ocean, ni, nj);
            }
        }
    }
};
