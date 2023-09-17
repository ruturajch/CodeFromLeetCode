
    class Solution {
public:

    class tuple{
        public:
        int node,cost,mask;
        tuple(int node,int mask,int cost){
            this -> node = node;
           this -> mask = mask;
            this -> cost = cost;
        }
    };

    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<tuple> q;
        set<pair<int,int>> vis;
        int all = (1<<n)-1;

        for(int i=0; i<n; i++)
        {
            tuple new_tuple(i,(1 << i),1);

            q.push(new_tuple);

            vis.insert({i,(1<<i)});
        }

        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();

            if(all == curr.mask) return curr.cost-1;

            for(auto it : graph[curr.node])
            {
                int total_mask = curr.mask | (1 << it);

                if(vis.find({it,total_mask}) == vis.end())
                {
                    tuple new_tuple(it,total_mask,curr.cost+1);

                    q.push(new_tuple);
                    vis.insert({it,total_mask});
                }
            }
        }
        return -1;
    }
};
