class Solution {
    boolean isSafe(char[][] board, int i, int j, int n){
        if(i>=n || j>=n) return false;
        //up
        for(int ii=i; ii>=0; ii--){
            if(board[ii][j]=='Q') return false;
        }
        //down
        for(int ii=i; ii<n; ii++){
            if(board[ii][j]=='Q') return false;
        }
        //right
        for(int jj=j; jj<n; jj++){
            if(board[i][jj]=='Q') return false;
        }
        //left
        for(int jj=j; jj>=0; jj--){
            if(board[i][jj]=='Q') return false;
        }        
        //left digonal-up
        for(int ii=i,jj=j; ii>=0&&jj>=0; ii--,jj--){
            if(board[ii][jj]=='Q') return false;
        }
        //left digonal-down
        for(int ii=i,jj=j; ii<n&&jj<n; ii++,jj++){
            if(board[ii][jj]=='Q') return false;
        }
        //right digonal-up
        for(int ii=i,jj=j; ii>=0&&jj<n; ii--,jj++){
            if(board[ii][jj]=='Q') return false;
        }      
        //right digonal-down
        for(int ii=i,jj=j; ii<n&&jj>=0; ii++,jj--){
            if(board[ii][jj]=='Q') return false;
        }              
        return true;         
    }
    List<List<String>> ans = new ArrayList<>();
    void find(char[][] board, int i, int j, int n, int q){
        for(int ii=0; ii<n ; ii++){
            if(ii==i) continue;//to avoid repetition
            for(int jj=0; jj<n; jj++){
                if(jj==j) break;//to avoid repetition
                if(isSafe(board, ii, jj, n)){
                    board[ii][jj]='Q';
                    find(board, ii, jj, n, q+1);
                    board[ii][jj]='.';                    
                }
            }
        }
        if(q==n){
            String s="";
            List<String> res = new ArrayList<>();
            for(int ii=0; ii<n ; ii++){
                for(int jj=0; jj<n; jj++){
                    if(board[ii][jj]=='Q'){
                        s+='Q';
                    }
                    else{
                        s+='.';
                    }
                }
                res.add(s);
                s="";
            }
            ans.add(res);
            return;
        }
    }
    public List<List<String>> solveNQueens(int n) {
        find(new char[n][n],-1,-1,n, 0);
        return ans;
    }
}