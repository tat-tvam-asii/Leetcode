class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int>& comb,int n,int k,int ind){
        if(k == 0 && n == 0){
            ans.push_back(comb);
            return;
        }
        
        for(int i = ind;i < 10 && i <= n;i++){
            comb.push_back(i);
            solve(ans,comb,n - i,k - 1,i + 1);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> comb;
        solve(ans,comb,n,k,1);
        return ans;
    }
};