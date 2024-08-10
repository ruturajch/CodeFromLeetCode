
class Solution {
private:
    vector<vector<int>> dim = {{0, 1}, {1,0}, {0,-1}, {-1,0}};
    void check(vector<vector<int>>& helperGrid, int l, int m, int n){
        if(l >= n || m >= n || l < 0 || m < 0 || helperGrid[l][m] == 1){
            return;
        }
        helperGrid[l][m] = 1;
        for(int i = 0; i < dim.size(); i++){
            check(helperGrid, l+dim[i][0], m+dim[i][1], n);
        }
        return;
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> helperGrid(3 * n, vector<int>(3 * n, 0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int l = 3 * i;
                int m = 3 * j;
                if(grid[i][j] == '/'){
                    helperGrid[l][m+2] = 1, helperGrid[l+1][m+1] = 1, helperGrid[l+2][m] = 1;
                }else if(grid[i][j] == '\\'){
                    helperGrid[l][m] = 1, helperGrid[l+1][m+1] = 1, helperGrid[l+2][m+2] = 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < 3*n; i++){
            for(int j = 0; j < 3*n; j++){
                if(helperGrid[i][j] == 0){
                    check(helperGrid, i, j, 3*n);
                    ans++;
                }
            }
        }
        return ans;
    }
};