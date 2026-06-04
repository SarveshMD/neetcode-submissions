class Solution {
public:
    bool dfs(int course, unordered_map<int, vector<int>>& prereq_map, unordered_set<int>& visitSet) {
        if (visitSet.contains(course)) return false;
        if (prereq_map[course].empty()) {
            return true;
        }
        visitSet.insert(course);
        for (int prereq: prereq_map[course]) {
            if (!dfs(prereq, prereq_map, visitSet)) return false;
        }
        prereq_map[course] = {};
        visitSet.erase(course);
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> prereq_map;
        for (auto prereq: prerequisites) {
            prereq_map[prereq[0]].push_back(prereq[1]);
        }
        unordered_set<int> visitSet;
        for (int i=0; i<numCourses; i++) {
            if (!dfs(i, prereq_map, visitSet)) return false;
        }
        return true;
    }
};
