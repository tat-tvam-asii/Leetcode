class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size(),ans1 = 0,ans2 = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n/2;j++){
                if(grid[i][j] != grid[i][n-j-1]) ans1++;
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m/2;j++){
                if(grid[j][i] != grid[m-j-1][i]) ans2++;
            }
        }
        return min(ans1,ans2);
    }
};