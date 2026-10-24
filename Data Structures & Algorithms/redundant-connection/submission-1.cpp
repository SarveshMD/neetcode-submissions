class Solution {
public:
    bool isConnected(unordered_map<int, vector<int>> &graph, int n)
    {
        vector<bool> visited(n + 1, false); // 0th el dummy, 1 indexed visited nodes

        queue<int> bfs_queue;
        bfs_queue.push(1);
        visited[1] = true;

        while (!bfs_queue.empty())
        {
            int curr_node = bfs_queue.front();
            bfs_queue.pop();

            for (int neighbor : graph[curr_node])
            {
                if (!visited[neighbor])
                {
                    bfs_queue.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
                return false;
        }

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        // { {2, 4}, {3, 4}, {1, 3}, {1, 2} }
        int n = edges.size(); // given that there are n edges and n vertices

        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            erase(graph[edges[i][0]], edges[i][1]);
            erase(graph[edges[i][1]], edges[i][0]);

            if (isConnected(graph, n))
            {
                return edges[i];
            }

            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);

            // remove edge i
            // if the graph is still connected
            //   return edge i
        }
        return {};
    }
};