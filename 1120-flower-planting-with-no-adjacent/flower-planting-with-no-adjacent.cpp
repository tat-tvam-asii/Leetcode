class Solution {
public:
    bool check(vector<int>& adjv,vector<int>& color,int col){
        for(int i : adjv){
            if(color[i] == col) return false;
        }
        return true;
    }

    bool solve(vector<vector<int>>& adj,vector<int>& ans,vector<int>& color,int n,int ind){
        if(ind == n) return true;
        for(int i = 1;i <= 4;i++){
            if(check(adj[ind],color,i)){
                ans.push_back(i);
                color[ind] = i;
                if(solve(adj,ans,color,n,ind+1)) return true;;
                ans.pop_back();
                color[ind] = 0;
            }
        }
        return false;
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        for(auto& v : paths){
            int v1 = v[0] - 1,v2 = v[1] - 1;
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }
        vector<int> ans;
        vector<int> color(n,0);
        int a = solve(adj,ans,color,n,0);
        return ans;
    }
};