class Solution {
public:
    void processInterval(vector<int> newInterval, vector<vector<int>>& res)
    {
        if(res.empty() || newInterval[0] > res.back()[1])
        {
            res.push_back(newInterval);
        }else
        {
            res.back()[1] = max(res.back()[1], newInterval[1]);
        }
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        bool newInterProcessed = false;
        
        for(int ii = 0; ii < n; ++ii)
        {
            if(newInterval[0] < intervals[ii][0])
            {
                newInterProcessed = true;
                processInterval(newInterval, res);
            }
            processInterval(intervals[ii], res);
        }
        if(!newInterProcessed)
        {
            processInterval(newInterval, res);
        }
        return res;
    }
};