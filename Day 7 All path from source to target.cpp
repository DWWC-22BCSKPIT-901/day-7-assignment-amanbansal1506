#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& result) {
    path.push_back(node);
    if (node == graph.size() - 1) {
        result.push_back(path);
    } else {
        for (int neighbor : graph[node]) {
            dfs(neighbor, graph, path, result);
        }
    }
    path.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> result;
    vector<int> path;
    dfs(0, graph, path, result);
    return result;
}

int main() {
    vector<vector<int>> graph1 = {{1,2},{3},{3},{}};
    vector<vector<int>> graph2 = {{4,3,1},{3,2,4},{3},{4},{}};
    
    vector<vector<int>> result1 = allPathsSourceTarget(graph1);
    vector<vector<int>> result2 = allPathsSourceTarget(graph2);

    for (const auto& path : result1) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (const auto& path : result2) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
