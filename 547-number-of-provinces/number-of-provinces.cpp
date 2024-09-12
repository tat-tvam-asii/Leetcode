class Solution {
    private:
        void dfs(int node,vector<int>& vis,vector<vector<int>>& adj){
            vis[node] = 1;
            for(int i = 0;i < adj[node].size();i++){
                if(adj[node][i] && !vis[i]) dfs(i,vis,adj);
            }
        }

    public:
        int findCircleNum(vector<vector<int>> adj) {
            vector<int> vis(adj.size(),0);
            int cnt = 0;
            for(int i = 0;i < adj.size();i++){
                if(!vis[i]){
                    cnt++;
                    dfs(i,vis,adj);
                }
            }
            return cnt;
        }
};