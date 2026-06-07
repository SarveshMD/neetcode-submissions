/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        for (auto interval: intervals) {
            cout << interval.start << " " << interval.end << endl;
        }
        int n = intervals.size();
        Interval lastInterval = intervals[0];
        for (int i=1; i<n; i++) {
            if (lastInterval.end > intervals[i].start) return false;
            lastInterval = intervals[i];
        }
        return true;
    }
};
