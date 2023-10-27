class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {

        int dirX = 0;
        int dirY = 1;

        int l = 0;
        int r = 0;

        vector<vector<int>> ansVector(n, vector<int>(n, 0));
        ansVector[l][r] = 1;
        int index = 2;
        while (index != (n * n) + 1)
        {
            int nrow = l + dirX;
            int ncol = r + dirY;
            if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= n || ansVector[nrow][ncol] != 0)
            {
                int temp = dirX;
                dirX = dirY;
                dirY = -1 * temp;
            }
            else
            {
                l = nrow;
                r = ncol;
                ansVector[l][r] = index++;
            }
        }
        return ansVector;
    }
};

// 0, 0 1
// 0, 1 2
// 0, 2 3
// 1, 0 8
// 1, 1 9
// 1, 2 4
