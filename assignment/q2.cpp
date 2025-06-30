// Edge with log(weight) for product minimization
struct Edge {
    int from, to;
    long long weight;
    double logWeight;
};

// Disjoint Set Union with path compression
int findRoot(int node, vector<int>& parent) {
    if (parent[node] == node) return node;
    return parent[node] = findRoot(node, parent);
}

// Union by rank, returns true if union was successful
bool unionSets(int nodeA, int nodeB, vector<int>& parent, vector<int>& rank) {
    int rootA = findRoot(nodeA, parent);
    int rootB = findRoot(nodeB, parent);
    if (rootA == rootB) return false;
    if (rank[rootA] < rank[rootB]) swap(rootA, rootB);
    parent[rootB] = rootA;
    if (rank[rootA] == rank[rootB]) rank[rootA]++;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numVertices, numEdges;
    cin >> numVertices >> numEdges;

    vector<Edge> allEdges(numEdges);
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        long long weight;
        cin >> u >> v >> weight;
        allEdges[i] = {u, v, weight, log((double)weight)};
    }

    // Sort by log-weight to minimize product
    sort(allEdges.begin(), allEdges.end(), [](const Edge& a, const Edge& b) {
        return a.logWeight < b.logWeight;
    });

    vector<int> parent(numVertices), rank(numVertices, 0);
    iota(parent.begin(), parent.end(), 0); // Initialize DSU

    vector<Edge> selectedEdges;
    long double totalProduct = 1.0L;

    for (const Edge& edge : allEdges) {
        if ((int)selectedEdges.size() == numVertices - 1) break;
        if (unionSets(edge.from, edge.to, parent, rank)) {
            selectedEdges.push_back(edge);
            totalProduct *= edge.weight;
        }
    }

    cout << "Edges in the Minimum Product Spanning Tree:\n";
    for (const Edge& edge : selectedEdges) {
        cout << edge.from << " — " << edge.to << "\n";
    }

    cout << "Minimum product: " << fixed << setprecision(0) << totalProduct << "\n";
    return 0;
}
