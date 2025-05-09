#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int node, vector<int>& parent) {
    if (parent[node] != node)
        parent[node] = findParent(parent[node], parent); // path compression
    return parent[node];
}

void unionSets(int u, int v, vector<int>& parent) {
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);
    if (pu != pv)
        parent[pu] = pv; // simply attach one to another (no rank)
}

int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compare);
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int mstWeight = 0;
    for (auto edge : edges) {
        if (findParent(edge.u, parent) != findParent(edge.v, parent)) {
            mstWeight += edge.weight;
            unionSets(edge.u, edge.v, parent);
            cout << "Edge added: " << edge.u << " - " << edge.v << " (weight " << edge.weight << ")\n";
        }
    }
    return mstWeight;
}

int main() {
    int n = 4; // number of nodes
    vector<Edge> edges = {
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
