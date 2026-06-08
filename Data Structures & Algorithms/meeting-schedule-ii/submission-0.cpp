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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts;
        vector<int> ends;
        for (auto interval: intervals) {
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int n = starts.size();
        int count = 0;
        int rooms = 0;
        for (int s=0, e=0; s<n; ) {
            if (starts[s] < ends[e]) {
                s++;
                count++;
            }
            else {
                e++;
                count--;
            }
            rooms = max(rooms, count);
        }
        return rooms;
    }
};
