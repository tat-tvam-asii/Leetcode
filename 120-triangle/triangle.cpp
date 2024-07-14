class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> curr(n+1,1e9),prev(n+1,1e9);
        prev[0] = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= i;j++){
                curr[j] = triangle[i-1][j-1] + min(prev[j-1],prev[j]);
            }
            prev = curr;
        }
        return *min_element(prev.begin(),prev.end());
    }
};