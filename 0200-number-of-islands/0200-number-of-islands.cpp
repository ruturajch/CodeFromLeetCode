class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        
        vector<vector<bool>> vis(n, vector<bool> (m,false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    ans++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j] = true;
                    while(!q.empty()){
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();

                        if( row!=0 && grid[row-1][col] == '1' && !vis[row-1][col]){
                            q.push({row-1,col});
                            vis[row-1][col] = true;
                        }
                        if( col!=0 && grid[row][col-1] == '1' && !vis[row][col-1]){
                            q.push({row,col-1});
                            vis[row][col-1] = true;
                        }
                        if( row!=n-1 && grid[row+1][col] == '1' && !vis[row+1][col]){
                            q.push({row+1,col});
                            vis[row+1][col] = true;
                        }
                        if( col!=m-1 && grid[row][col+1] == '1' && !vis[row][col+1]){
                            q.push({row,col+1});
                            vis[row][col+1] = true;
                        }
                    }
                }
            }
        }
        return ans;
    }
};