class Solution {
public:
    bool dfs(int node, int prev, unordered_map<int, vector<int>>& adjacency_map, unordered_set<int>& visited) {
        if (visited.contains(node)) return false;
        if (adjacency_map[node].empty()) return true;
        visited.insert(node);
        for (int next: adjacency_map[node]) {
            if (next == prev) continue;
            if (!dfs(next, node, adjacency_map, visited)) return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n == 1 && edges.empty()) return true;
        unordered_map<int, vector<int>> adjacency_map;
        for (auto edge: edges) {
            adjacency_map[edge[0]].push_back(edge[1]);
            adjacency_map[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited;
        return dfs(0, -1, adjacency_map, visited) && (visited.size() == n);
    }
};
