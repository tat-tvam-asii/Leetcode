class Solution {
  private:
    void dfs(int x,int y,vector<vector<bool>>& vis,vector<vector<char>>& grid){
        vis[x][y] = 1;
        int n = grid.size(),m = grid[0].size();
        for(int i = -1;i <= 1;i++){
            for(int j = -1;j <= 1;j++){
                if(x+i >= 0 && x+i < n && y+j >= 0 && y+j < m){
                    if(abs(i+j) == 1 && grid[x+i][y+j] == '1' && !vis[x+i][y+j]) dfs(x+i,y+j,vis,grid);
                }
            }
        }
    }
    
  public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        int cnt = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};