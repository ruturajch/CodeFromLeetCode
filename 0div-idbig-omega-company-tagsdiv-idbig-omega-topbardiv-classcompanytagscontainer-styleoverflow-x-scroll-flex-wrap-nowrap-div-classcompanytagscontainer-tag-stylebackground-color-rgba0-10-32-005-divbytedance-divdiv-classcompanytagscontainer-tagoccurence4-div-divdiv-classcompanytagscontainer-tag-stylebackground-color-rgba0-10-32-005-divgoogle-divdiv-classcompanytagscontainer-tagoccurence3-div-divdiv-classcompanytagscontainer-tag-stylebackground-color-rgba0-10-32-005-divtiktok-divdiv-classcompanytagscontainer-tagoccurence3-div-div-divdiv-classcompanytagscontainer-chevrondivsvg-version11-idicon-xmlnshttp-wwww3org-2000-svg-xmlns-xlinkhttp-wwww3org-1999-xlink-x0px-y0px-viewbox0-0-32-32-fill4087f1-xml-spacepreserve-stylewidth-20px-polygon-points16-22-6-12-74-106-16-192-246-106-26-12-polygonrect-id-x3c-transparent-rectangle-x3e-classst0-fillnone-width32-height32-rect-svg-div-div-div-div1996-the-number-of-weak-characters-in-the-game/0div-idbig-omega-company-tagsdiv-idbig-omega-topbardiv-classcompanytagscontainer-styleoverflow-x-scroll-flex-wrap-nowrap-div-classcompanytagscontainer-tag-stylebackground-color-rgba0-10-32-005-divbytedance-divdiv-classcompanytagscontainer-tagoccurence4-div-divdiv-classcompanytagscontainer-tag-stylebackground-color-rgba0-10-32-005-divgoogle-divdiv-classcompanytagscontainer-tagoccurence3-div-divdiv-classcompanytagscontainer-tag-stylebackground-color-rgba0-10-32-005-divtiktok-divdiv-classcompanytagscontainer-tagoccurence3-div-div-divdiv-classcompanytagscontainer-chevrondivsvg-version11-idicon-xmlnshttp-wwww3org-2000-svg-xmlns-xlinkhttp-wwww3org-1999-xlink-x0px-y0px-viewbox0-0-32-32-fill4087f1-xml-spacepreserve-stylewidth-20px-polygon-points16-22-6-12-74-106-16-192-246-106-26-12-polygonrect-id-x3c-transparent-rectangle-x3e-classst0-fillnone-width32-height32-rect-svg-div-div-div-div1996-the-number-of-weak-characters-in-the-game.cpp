class Solution {
public:
    static bool check(vector<int>& a, vector<int>& b){
    if (a[0] == b[0]) {
        return a[1] > b[1];
    }
    return a[0] < b[0];
} 

int numberOfWeakCharacters(vector<vector<int>>& properties) {
    sort(properties.begin(), properties.end(), check);

    int ansCount = 0;
    int curAttack = properties.back()[0];
    int maxdef = properties.back()[1];

    for (int i = properties.size() - 2; i >= 0; i--) {
        

        if (properties[i][1] < maxdef) {
            ansCount++;
        }

        if (maxdef < properties[i][1]) {
            maxdef = properties[i][1];
            curAttack = properties[i][0];
        }
    }

    return ansCount;
}

};