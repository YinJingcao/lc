/**
 * @file 56_Merge_Intervals.cpp
 * @author yinjingcao
 * @date 2018/03/27 11:17:53
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
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() <= 1) return intervals;
        vector<Interval> result;
        sort(intervals.begin(), intervals.end(), compare);
        int s = intervals[0].start;
        int e = intervals[0].end;
        int idx = 1;
        result.push_back(intervals[0]);
        for (; idx < intervals.size(); ++idx) {
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
            if (!re) {
                result[result.size() - 1].start = s;
                result[result.size() - 1].end = e;
            } else {
                Interval interval(s, e);
                result.push_back(interval);
            }
        }
        return result;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
