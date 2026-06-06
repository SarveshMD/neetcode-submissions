class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        });
        vector<vector<int>> output;
        output.push_back(intervals[0]);
        int oi = 0;
        int n = intervals.size();
        for (int i=1; i<n; i++) {
            if (output[oi][1] >= intervals[i][0]) {
                output[oi] = {min(output[oi][0], intervals[i][0]), max(output[oi][1], intervals[i][1])};
            }
            else {
                output.push_back(intervals[i]);
                oi++;
            }
        }
        return output;
    }
};
