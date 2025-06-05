class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int>& comb,int n,int k,int ind){
        if(ind > n){
            if(k == 0){
                ans.push_back(comb);
                return;
            }
            return;
        }
        
        comb.push_back(ind);
        solve(ans,comb,n,k-1,ind+1);
        comb.pop_back();
        solve(ans,comb,n,k,ind+1);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        solve(ans,comb,n,k,1);
        return ans;
    }
};