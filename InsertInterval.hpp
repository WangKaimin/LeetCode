#ifndef INSERTINTERVAL_HPP_INCLUDED
#define INSERTINTERVAL_HPP_INCLUDED
#include <vector>
using namespace std;
/**
 * Definition for an interval. */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert04(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result(intervals);
        vector<Interval>::iterator it = result.begin();
        while(it != result.end())
        {
            if(newInterval.end < (*it).start) {
                result.insert(it, newInterval);
                return result;
            }
            else if(newInterval.start > (*it).end) {
                it++;
            }
            else if(newInterval.start <= (*it).start && newInterval.end >= (*it).end) {
                it = result.erase(it);
            }
            else {
                newInterval.start = min(newInterval.start, (*it).start);
                newInterval.end = max(newInterval.end, (*it).end);
                it = result.erase(it);
            }
        }
        result.insert(result.end(), newInterval);
        return result;
    }

public:
    vector<Interval> insert03(vector<Interval> &intervals, Interval newInterval) {
        int i=0;
        while(i<intervals.size())
        {
            if(newInterval.end < intervals[i].start) {
                intervals.insert(intervals.begin()+i, newInterval);
                return intervals;
            }
            else if(newInterval.start > intervals[i].end) {
                i++;
            }
            else if(newInterval.start <= intervals[i].start && newInterval.end >= intervals[i].end) {
                intervals.erase(intervals.begin()+i);
            }
            else {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
                intervals.erase(intervals.begin()+i);
            }
        }
        intervals.insert(intervals.end(), newInterval);
        return intervals;
    }
public:
    vector<Interval> insert02(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval>::iterator it = intervals.begin();
        while(it != intervals.end())
        {
            if(newInterval.end < (*it).start) {
                intervals.insert(it, newInterval);
                return intervals;
            }
            else if(newInterval.start > (*it).end) {
                it++;
            }
            else if(newInterval.start <= (*it).start && newInterval.end >= (*it).end) {
                it = intervals.erase(it);
            }
            else {
                newInterval.start = min(newInterval.start, (*it).start);
                newInterval.end = max(newInterval.end, (*it).end);
                it = intervals.erase(it);
            }
        }
        intervals.insert(intervals.end(), newInterval);
        return intervals;
    }
public:
    vector<Interval> insert01(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval>::iterator it = intervals.begin();
        while(it != intervals.end())
        {
            if(newInterval.end < it->start) {
                intervals.insert(it, newInterval);
                return intervals;
            }
            else if(newInterval.start > it->end)
                it++;
            else {
                newInterval.start = min(newInterval.start, it->start);
                newInterval.end = max(newInterval.end, it->end);
                it = intervals.erase(it);
            }
        }
        intervals.insert(intervals.end(), newInterval);
        return intervals;
    }
    void test()
    {
        Solution sol;
        vector<Interval> vals;
        Interval val;
        for(int i=1; i<=10000; i+=2)
        {
            val.start = i;
            val.end = i+1;
            vals.push_back(val);
        }
        for(vector<Interval>::iterator it = vals.begin(); it != vals.end(); it++)
        {
            cout<<it->start<<"\t"<<it->end<<endl;
        }
        Interval t(5 ,7);
        sol.insert04(vals, t);
        cout<<"--------------------\n";
        for(vector<Interval>::iterator it = vals.begin(); it != vals.end(); it++)
        {
            cout<<it->start<<"\t"<<it->end<<endl;
        }
    }
};

#endif // INSERTINTERVAL_HPP_INCLUDED
