class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> output;
        for (int i=0; i<n; i++) {
            if (newInterval[1] < intervals[i][0]) {
                output.push_back(newInterval);
                for (int j=i; j<n; j++) {
                    output.push_back(intervals[j]);
                }
                return output;
            }
            else if (intervals[i][1] < newInterval[0]) {
                output.push_back(intervals[i]);
            }
            else {
                newInterval = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
            }
        }
        output.push_back(newInterval);
        return output;
    }
};
