class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        unordered_map<int, vector<pair<int, double>>> adjlist;
        for(int i = 0; i < edges.size(); i++){
            auto it = edges[i];
            adjlist[it[0]].push_back({it[1], succProb[i]});
            adjlist[it[1]].push_back({it[0], succProb[i]});
        }
        vector<bool> helperVector(n, false);
        
        priority_queue<pair<double, int>> pq;
        pq.push({1, start_node});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            helperVector[it.second] = true;
            if(it.second == end_node){
                return it.first;
            }
            cout << it.second << endl;
            for(int i = 0; i < adjlist[it.second].size(); i++){
                if(!helperVector[adjlist[it.second][i].first])
                    pq.push({adjlist[it.second][i].second * it.first, adjlist[it.second][i].first});
            }
        }
        return 0;
    }
};