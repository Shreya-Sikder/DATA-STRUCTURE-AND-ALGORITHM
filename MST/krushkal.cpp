#include<bits/stdc++.h>
using namespace std;


class DisjointSet {
    vector<int> rank, parent;
public :
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }


    int findPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }


    void unionByRank(int u, int v){
        int ul_u = findPar(u);
        int ul_v = findPar(v);
        if(ul_u == ul_v) return;
        if(rank[ul_u] < rank[ul_v]){
            parent[ul_u] = ul_v;
        } else if(rank[ul_u] > rank[ul_v]){
            parent[ul_v] = ul_u;
        } else{
            parent[ul_v] = ul_u;
            rank[ul_u]++;
        }
    }
};


int kruskalMST(int n, vector<pair<int, pair<int, int>>> &edges) {
    sort(edges.begin(), edges.end()); // Sort edges based on weight
    DisjointSet ds(n); // Create a disjoint set for union-find operations
    int mstCost = 0; // Total cost of the minimum spanning tree
    // vector<pair<int, int>> mstEdges; // To store edges in the MST


    for(auto it : edges) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;


        if(ds.findPar(u) != ds.findPar(v)) { // If u and v are in different sets
            ds.unionByRank(u, v); // Union the sets
            mstCost += wt; // Add weight to the total cost
            // mstEdges.push_back({u, v}); // Add edge to the MST
        }
    }


    return mstCost; // Return the total cost of the minimum spanning tree
}


int main(){

    int n, m;
    cin >> n >> m; // Read number of vertices and edges
    vector<pair<int, pair<int, int>>> edges; // To store edges in the format (weight, (u, v))
    for(int i = 0; i < m; i++){
        int u, v, wt;
        cin >> u >> v >> wt; // Read each edge
        edges.push_back({wt, {u, v}}); // Add edge to the list
    }


    int mstCost = kruskalMST(n, edges); // Perform Kruskal's algorithm to find the minimum spanning tree
    cout << "Cost of Minimum Spanning Tree: " << mstCost << endl; // Print the cost of the minimum spanning tree




    return 0; // Return 0 to indicate successful execution
}
