class Solution {
public:
    long long dfs(int node, vector<vector<int>> &adj, vector<int> &val, vector<int> &vis){
        if(vis[node]) return 0;
        vis[node] = 1;
        int n = adj.size();
        
        long long mn = 0;
        for(int child: adj[node]){
            long long temp = dfs(child, adj, val, vis);
            mn += temp;
        }
        if(mn==0) return val[node]+0ll;
        return min(mn, val[node]+0ll);
    }
    
    long long total(int node, vector<vector<int>> &adj, vector<int> &val, vector<int> &vis){
        if(vis[node]) return 0;
        vis[node] = 1;
    	long long sum=val[node];
    	for(int child: adj[node]){
    		sum += total(child, adj, val, vis);
    	}
    	return sum;
    }
    
    long long maximumScoreAfterOperations(vector<vector<int>>& e, vector<int>& values) {
        int n = e.size();
        vector<vector<int>> adj(n+1);
        
        for(int i=0; i<n; i++){
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
        }

        vector<int> vis(n+1);
        
        
        long long ttl = total(0, adj, values, vis);
        for(int &va: vis) va=0;
        long long stay = dfs(0, adj, values, vis);
        
        if(stay==0) stay = values[0];
        stay = min(values[0]+0ll, stay);
        return ttl-stay;
            
    }
};