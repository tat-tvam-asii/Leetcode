class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int>& subseq,vector<int>& candidates,int target,int sum,int ind){
        if(sum == target){
            ans.push_back(subseq);
            return;
        }
        if(ind == candidates.size()) return;
        if(sum + candidates[ind] > target) return;
        subseq.push_back(candidates[ind]);
        sum += candidates[ind];
        solve(ans,subseq,candidates,target,sum,ind+1);
        subseq.pop_back();
        sum -= candidates[ind];
        int temp = candidates[ind];
        while(ind < candidates.size() && candidates[ind] == temp) ind++;
        solve(ans,subseq,candidates,target,sum,ind);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subseq;
        sort(candidates.begin(),candidates.end());
        solve(ans,subseq,candidates,target,0,0);
        return ans;
    }
};