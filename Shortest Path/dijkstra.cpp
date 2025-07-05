#include<bits/stdc++.h>

using namespace std;

// Dijkstra's algorithm to find shortest distances from 'source'
vector<int> dijkstra(int n, vector<pair<int, int>> graph[], int source) {
    vector<int> distance(n + 1, INT_MAX); // Distance from source to each node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

    distance[source] = 0;
    minHeap.push({0, source});

    while (!minHeap.empty()) {
        auto [dist, node] = minHeap.top(); // current shortest distance and node
        minHeap.pop();

        for (auto [neighbor, weight] : graph[node]) {
            int newDist = dist + weight;
            if (newDist < distance[neighbor]) {
                distance[neighbor] = newDist;
                minHeap.push({newDist, neighbor});
            }
        }
    }

    return distance;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> graph[n + 1];

    // Read the edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // undirected graph
    }

    int source;
    cin >> source;

    vector<int> result = dijkstra(n, graph, source);

    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 1; i <= n; i++) {
        if (result[i] == INT_MAX)
            cout << "Node " << i << ": Unreachable\n";
        else
            cout << "Node " << i << ": " << result[i] << "\n";
    }

    return 0;
}
