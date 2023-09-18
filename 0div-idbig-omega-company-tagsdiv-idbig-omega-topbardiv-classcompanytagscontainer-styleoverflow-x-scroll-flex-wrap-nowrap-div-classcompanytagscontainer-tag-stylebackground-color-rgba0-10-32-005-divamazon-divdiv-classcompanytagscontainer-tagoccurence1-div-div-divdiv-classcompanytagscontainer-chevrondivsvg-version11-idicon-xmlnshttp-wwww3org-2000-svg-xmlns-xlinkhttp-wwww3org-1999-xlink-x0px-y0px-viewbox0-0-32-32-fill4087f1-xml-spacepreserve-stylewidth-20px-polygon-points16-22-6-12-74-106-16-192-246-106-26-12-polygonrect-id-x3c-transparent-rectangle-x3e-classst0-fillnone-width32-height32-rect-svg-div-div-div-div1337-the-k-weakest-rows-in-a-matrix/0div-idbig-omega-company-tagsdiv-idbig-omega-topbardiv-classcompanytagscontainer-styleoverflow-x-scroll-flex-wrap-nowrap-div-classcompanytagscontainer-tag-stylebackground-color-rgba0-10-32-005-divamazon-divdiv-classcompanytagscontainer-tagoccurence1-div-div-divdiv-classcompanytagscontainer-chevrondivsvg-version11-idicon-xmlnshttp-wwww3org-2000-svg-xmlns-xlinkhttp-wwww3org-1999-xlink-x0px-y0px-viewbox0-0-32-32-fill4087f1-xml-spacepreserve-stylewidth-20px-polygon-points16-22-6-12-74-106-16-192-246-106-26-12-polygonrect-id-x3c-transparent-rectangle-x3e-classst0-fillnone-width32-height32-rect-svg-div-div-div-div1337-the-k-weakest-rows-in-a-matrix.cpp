class Solution {
public:
    static bool check(pair<int, int> &a, pair<int, int> &b)
    {
        if(a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    }
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {

        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int, int>> helperVector;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j])
                    count++;
                else
                    break;
            }
            helperVector.push_back({i, count});
        }

        sort(helperVector.begin(), helperVector.end(), check);
        vector<int> ansVector;
        for (int i = 0; i < k; i++)
        {
            ansVector.emplace_back(helperVector[i].first);
        }
        return ansVector;
    }
};