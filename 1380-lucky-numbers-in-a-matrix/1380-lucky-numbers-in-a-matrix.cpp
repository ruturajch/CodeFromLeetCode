struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2> &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_set<pair<int, int>, pair_hash> us;
        vector<int> ans;

        // Find the minimum elements in each row
        for(int i = 0; i < n; i++) {
            pair<int, int> min = {i, 0};
            int temp = matrix[i][0];
            for(int j = 1; j < m; j++) {
                if(temp > matrix[i][j]) {
                    min = {i, j};
                    temp = matrix[i][j];
                }
            }
            us.insert(min);
        }

        // Find the maximum elements in each column
        for(int i = 0; i < m; i++) {
            pair<int, int> max = {0, i};
            int temp = matrix[0][i];
            for(int j = 1; j < n; j++) {
                if(temp < matrix[j][i]) {
                    max = {j, i};
                    temp = matrix[j][i];
                }
            }
            // Check if the maximum element is also a minimum element in its row
            if(us.find(max) != us.end()) {
                ans.push_back(matrix[max.first][max.second]);
            }
        }

        return ans;
    }
};