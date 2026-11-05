class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals));
        int count = 0;
        int i = 0, j = 1;
        int n = intervals.size();

        while(j < n){
            vector<int>curr_intervals = intervals[i];
            vector<int>next_intervals = intervals[j];

            int cs = curr_intervals[0];
            int ce = curr_intervals[1];

            int ns = next_intervals[0];
            int ne = next_intervals[1];

            if(ce <= ns){ // no overlapping
                i = j;
                j++;
            }
            else if(ce <= ne){
                j++;
                count++;
            }
            else if(ce > ne){
                i = j;
                j++;
                count++;
            }
        }
        return count;
    }
};