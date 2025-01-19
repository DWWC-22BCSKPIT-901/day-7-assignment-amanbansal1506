#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) return {0};
    vector<int> degree(n, 0);
    vector<vector<int>> adj(n);
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
        degree[edge[0]]++;
        degree[edge[1]]++;
    }
    queue<int> leaves;
    for (int i = 0; i < n; i++) {
        if (degree[i] == 1) leaves.push(i);
    }
    int remainingNodes = n;
    while (remainingNodes > 2) {
        int leafCount = leaves.size();
        remainingNodes -= leafCount;
        for (int i = 0; i < leafCount; i++) {
            int leaf = leaves.front();
            leaves.pop();
            for (int neighbor : adj[leaf]) {
                degree[neighbor]--;
                if (degree[neighbor] == 1) leaves.push(neighbor);
            }
        }
    }
    vector<int> result;
    while (!leaves.empty()) {
        result.push_back(leaves.front());
        leaves.pop();
    }
    return result;
}

int main() {
    vector<vector<int>> edges1 = {{1, 0}, {1, 2}, {1, 3}};
    vector<vector<int>> edges2 = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
    
    vector<int> result1 = findMinHeightTrees(4, edges1);
    vector<int> result2 = findMinHeightTrees(6, edges2);
    
    cout << "MHT Roots for edges1: ";
    for (int root : result1) {
        cout << root << " ";
    }
    cout << endl;
    
    cout << "MHT Roots for edges2: ";
    for (int root : result2) {
        cout << root << " ";
    }
    cout << endl;
    
    return 0;
}
