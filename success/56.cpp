class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(begin(intervals), end(intervals), 
             [](const vector<int>& i1, const vector<int>& i2) {
                 return (i1[0] != i2[0]) ? i1[0] < i2[0] : i1[1] < i2[1];
             });
        
        vector<vector<int>> result;
        
        vector<int> last_interval = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (IsIntersect(last_interval, intervals[i])) {
                vector<int> new_interval = {
                    min(last_interval[0], intervals[i][0]),
                    max(last_interval[1], intervals[i][1])
                };
                last_interval = new_interval;
            }
            else {
                result.push_back(last_interval);
                last_interval = intervals[i];
            }
        }
        
        result.push_back(last_interval);
        return result;
    }

private:
    bool IsIntersect(const vector<int>& i1, const vector<int>& i2) {
        return i2[0] <= i1[1] && i2[0] >= i1[0];
    }
};