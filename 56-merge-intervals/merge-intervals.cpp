class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[&](vector<int> a,vector<int> b) -> bool{
            return a[0] < b[0];
        });
        vector<vector<int>> ans;
        vector<int> temp = {intervals[0][0],intervals[0][1]};
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] <= temp[1]){
                temp[1] = max(intervals[i][1],temp[1]);
            }
            else{
                ans.push_back(temp);
                temp = intervals[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};