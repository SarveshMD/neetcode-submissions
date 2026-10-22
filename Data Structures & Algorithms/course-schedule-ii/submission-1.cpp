class Solution {
public:
    bool fill_res(int numCourses, unordered_map<int, vector<int>> &dependency_graph,
                vector<int> &res, vector<bool> &completed, vector<bool> &visited, int currCourse)
    {
        if (completed[currCourse])
            return true;

        if (visited[currCourse])
            return false;
        visited[currCourse] = true;

        for (int dep : dependency_graph[currCourse])
        {
            bool noLoop = fill_res(numCourses, dependency_graph, res, completed, visited, dep);
            if (!noLoop)
            {
                return false;
            }
        }

        completed[currCourse] = true;
        res.push_back(currCourse);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> dependency_graph;

        for (auto prereq : prerequisites)
        {
            dependency_graph[prereq[0]].push_back(prereq[1]);
        }

        vector<int> res;
        vector<bool> completed(numCourses, false);

        for (int i = 0; i < numCourses; i++)
        {
            vector<bool> visited(numCourses, false);
            bool noLoop = fill_res(numCourses, dependency_graph, res, completed, visited, i);
            if (!noLoop)
                return {};
        }

        return res;
    }
};
