class Solution {
public:

int parent[3002]; //to store parent of each node
int size[3002];   //to store the size of component

void make(int v) {   // initializing a component with one node
    parent[v] = v;
    size[v] = 1;
}

int findPar(int a) {    // returns parent of node a
    if (a == parent[a]) return a;
    else return parent[a] = findPar(parent[a]);
}

void Union(int a, int b) {   // connects two nodes in one component
    a = findPar(a);
    b = findPar(b);

    if (a == b) return;

    if (size[a] < size[b]) {
        swap(a, b);
    }

    parent[b] = a;
    size[a] += size[b];
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n = edges.size();
        for (int i = 1; i <= n; i++) make(i);
        for (int i = 0; i < n; i++) {
            int u = edges[i][0], v = edges[i][1];
            int a = findPar(u), b = findPar(v);
            if (a == b) {   // u and v are already connected, return current edge as it is redundant
                return {u, v};
            } else {
                Union(u, v);  // connects u and v
            }
        }
        return ans;
    }
};