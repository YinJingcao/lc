 /**
 * @file 57_Insert_Interval.cpp
 * @author yinjingcao
 * @date 2018/03/27 14:20:00
 * @version $Revision$ 
 * @brief 
 *  
 **/


//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compare(Interval& a, Interval& b) {
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> result;
        result.push_back(intervals[0]);
        int s = intervals[0].start;
        int e = intervals[0].end;
        for (size_t idx = 1; idx < intervals.size(); ++idx) {
            bool re = true;
            int cur_s = intervals[idx].start;
            int cur_e = intervals[idx].end;
            if (cur_s <= e) {
                re = false;
            } else {
                s = cur_s;
            }
            if (e < cur_e) {
                e = cur_e;
            }
            if (re) {
                Interval interval(s, e);
                result.push_back(interval);
            } else {
                result[result.size() - 1].start = s;
                result[result.size() - 1].end = e;
            }
        }
        return result;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
