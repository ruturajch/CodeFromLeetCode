class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n) {
            return {};
        }
        vector<vector<int>> ansVector;
        auto it = original.begin();
        while(it != original.end()){
            vector<int> temp(it, it+n);
            ansVector.push_back(temp);
            it = it+n;
        }
        return ansVector;
    }
};