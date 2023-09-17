class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, int>> adjList[n];
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int distance = abs(points[i][0] - points[j][0])+abs(points[i][1] - points[j][1]);
                adjList[i].push_back(make_pair(j, distance));
                adjList[j].push_back(make_pair(i, distance));
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;
        vector<int> tapVector(n, 0);
        pq.push({0, 0});
        int ansSum = 0;
        
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            if(tapVector[front.second] == 1) continue;
            tapVector[front.second] = 1;
            ansSum += front.first;
            for(auto i : adjList[front.second]){
                if(tapVector[i.first] == 0)
                    pq.push({i.second, i.first});
            } 
        }
        return ansSum;
    }
};