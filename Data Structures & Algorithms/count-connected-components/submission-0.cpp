class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>>& adjacency_set, vector<int>& visited) {
        visited[node] = 1;
        for (int nextNode: adjacency_set[node]) {
            if (!visited[nextNode]) dfs(nextNode, adjacency_set, visited);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjacency_set;
        for (auto edge: edges) {
            adjacency_set[edge[0]].push_back(edge[1]);
            adjacency_set[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n, 0);
        int components = 0;
        for (int i=0; i<n; i++) {
            if (!visited[i]) {
                components++;
                dfs(i, adjacency_set, visited);
            }
        }
        return components;
    }
};
