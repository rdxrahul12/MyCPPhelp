#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    int u, v, weight;
};

// Comparator to sort edges by their weights
bool compare(edge a, edge b) {
    return a.weight < b.weight;
}

// Find with path compression
int findparent(int node, vector<int>& parent) {
    if (parent[node] != node)
        parent[node] = findparent(parent[node], parent); // path compression
    return parent[node];
}

// Union by rank
void unionsets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int pu = findparent(u, parent);
    int pv = findparent(v, parent);
    
    if (pu != pv) {
        // Union by rank: attach smaller tree under larger tree
        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pu] = pv;
            rank[pv]++; // Increase rank if both trees are of same rank
        }
    }
}

int kruskal(int n, vector<edge>& edges) {
    sort(edges.begin(), edges.end(), compare);
    vector<int> parent(n), rank(n, 0);

    // Initialize parent array (every node is its own parent initially)
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int mstWeight = 0;

    // Process edges
    for (auto edge : edges) {
        if (findparent(edge.u, parent) != findparent(edge.v, parent)) {
            mstWeight += edge.weight;
            unionsets(edge.u, edge.v, parent, rank); // Perform union
            cout << "Edge added: " << edge.u << " - " << edge.v << " (weight: " << edge.weight << ")" << endl;
        }
    }

    return mstWeight;
}

int main() {
    int n = 4;
    vector<edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int totalWeight = kruskal(n, edges);
    cout << "Total weight of MST: " << totalWeight << endl;

    return 0;
}
