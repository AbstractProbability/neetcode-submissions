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
        vector<pair<int, int>> v(intervals.size());
        for (int i = 0; i<intervals.size(); i++) {
            v[i].first = intervals[i].start;
            v[i].second = intervals[i].end;
        }
        sort(v.begin(), v.end());
        for (int i = 1; i<intervals.size(); i++) {
            if (v[i].first < v[i-1].second) { return false; }
        }
        return true;
    }
};
