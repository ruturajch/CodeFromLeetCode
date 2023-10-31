class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ansVector(n);
        int cur = -1;
        for(int i = n - 1; i >= 0; i--){
            ansVector[i] = cur;
            cur = max(cur, arr[i]);
        }
        return ansVector;
    }
};