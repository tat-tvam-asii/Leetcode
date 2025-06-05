class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int>& comb,int n,int k,int ind){
        if(ind == 10){
            if(k == 0 && n == 0){
                ans.push_back(comb);
                return;
            }
            return;
        }
        
        comb.push_back(ind);
        solve(ans,comb,n-ind,k-1,ind+1);
        comb.pop_back();
        solve(ans,comb,n,k,ind+1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> comb;
        solve(ans,comb,n,k,1);
        return ans;
    }
};