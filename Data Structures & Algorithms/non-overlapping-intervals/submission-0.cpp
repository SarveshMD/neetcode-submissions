class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[0] < b[0]);
        });
        int n = intervals.size();
        int lastEnd = intervals[0][1];
        int removed = 0;
        for (int i=1; i<n; i++) {
            if (intervals[i][0] < lastEnd) {
                lastEnd = min(lastEnd, intervals[i][1]);
                removed++;
            }
            else {
                lastEnd = intervals[i][1];
            }
        }
        return removed;
    }
};
