#include<bits/stdc++.h>
using namespace std;
int PrimsMST(int n, vector<pair<int, int>> adj[]) {
    vector<int> visited(n + 1, false); // To keep track of visited nodes
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap priority queue to select the edge with the minimum weight
    int mstCost = 0; // Total cost of the minimum spanning tree
    pq.push({0,0});
    while(!pq.empty()){
        auto it = pq.top(); // Get the edge with the minimum weight
        pq.pop();
        int node = it.second; // Get the node from the edge
        int weight = it.first; // Get the weight of the edge
        if(visited[node]) continue; // If the node is already visited, skip it
        visited[node] = true; // Mark the node as visited
        mstCost += weight; // Add the weight of the edge to the total cost
        // Traverse all adjacent vertices
        for(auto it2 : adj[node]) {
            int adjNode = it2.first; // Get the adjacent node
            int edgeWeight = it2.second; // Get the weight of the edge
            if(!visited[adjNode]) { // If the adjacent node is not visited
                pq.push({edgeWeight, adjNode}); // Add the edge to the priority queue
            }
        }
    }
    return mstCost; // Return the total cost of the minimum spanning tree
}
int main(){
    int n, m;
    cin >> n >> m; // Read number of vertices and edges


    vector<pair<int, int>> adj[n+1]; // Adjacency list for the weighted graph
    for(int i=0; i<m; i++){
        int u, v, wt;
        cin >> u >> v >> wt; // Read each edge
        adj[u].push_back({v, wt}); // Add edge to the adjacency list
        adj[v].push_back({u, wt}); // Since it's an undirected graph, add both directions
    }


    int mstCost = PrimsMST(n, adj); // Perform Prim's algorithm to find the minimum spanning tree
    cout << "Cost of Minimum Spanning Tree: " << mstCost << endl; // Print the cost of the minimum spanning tree


    return 0;
}
