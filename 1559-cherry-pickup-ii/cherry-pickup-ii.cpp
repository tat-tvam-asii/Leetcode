class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size(),c = grid[0].size();
        vector<vector<int>> prev(c,vector<int>(c,-1));
        vector<vector<int>> curr(c,vector<int>(c,-1));

        for(int j1 = 0;j1 < c;j1++){
            for(int j2 = 0;j2 < c;j2++){
                if(j1 == j2) prev[j1][j2] = grid[r-1][j1];
                else prev[j1][j2] = grid[r-1][j1] + grid[r-1][j2];
            }
        }

        for(int i = r-2;i >= 0;i--){
            for(int j1 = 0;j1 < c;j1++){
                for(int j2 = 0;j2 < c;j2++){
                    int maxi = INT_MIN;
                    for(int di = -1;di <= 1;di++){
                        for(int dj = -1;dj <= 1;dj++){
                            int ans;
                            if(j1 == j2) ans = grid[i][j1];
                            else ans = grid[i][j1] + grid[i][j2];
                            if(j1+di < 0 || j1+di >= c || j2+dj < 0 || j2+dj >= c) ans += -1e8;
                            else ans += prev[j1+di][j2+dj];
                            maxi = max(maxi,ans);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            prev = curr;
        }
        return prev[0][c-1];
    }
};