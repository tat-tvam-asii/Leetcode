class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        for(int i = 0;i < n;i++){
            if(grid[i][0] == 0){
                for(int j = 0;j < m;j++) grid[i][j] = !grid[i][j];
            }
        }
        int ans = 0;
        for(int i = 0;i < m;i++){
            int tmp = 0;
            for(int j = 0;j < n;j++){
                tmp += grid[j][i];
            }
            tmp = max(tmp,n-tmp);
            ans += (1 << (m-i-1)) * tmp;
        }
        return ans;
    }
};