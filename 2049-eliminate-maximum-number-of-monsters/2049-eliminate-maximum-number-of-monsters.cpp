class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> helperVector;
        int n = dist.size();
        for(int i = 0; i < n; i++){
            helperVector.push_back((double)dist[i]/speed[i]);
        }
        int cost = 1;
        sort(helperVector.begin(), helperVector.end());
        for(int i = 1; i < n; i++){
            if(helperVector[i] - i > 0){
                cost++;
               
            }else
             break;
        }
        return cost;
    }
};