class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        vector<int> temp = newInterval;
        for(int i=0;i<intervals.size();i++){
            int x = intervals[i][0],y = intervals[i][1];
            if(temp[0] > y) ans.push_back(intervals[i]);
            else if(temp[1] < x){
                ans.push_back(temp);
                temp = intervals[i];
            }
            else{
                temp[0] = min(temp[0],x);
                temp[1] = max(temp[1],y);
            }
        }
        ans.push_back(temp);
        return ans;
    }
};