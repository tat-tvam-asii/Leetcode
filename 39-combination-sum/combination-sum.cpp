class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int>& subseq,vector<int>& candidates,int target,int ind){
        if(!target){
            ans.push_back(subseq);
            return;
        }
        for(int i = ind;i < candidates.size() && target >= candidates[i];i++){
            subseq.push_back(candidates[i]);
            solve(ans,subseq,candidates,target - candidates[i],i);
            subseq.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subseq;
        sort(candidates.begin(),candidates.end());
        solve(ans,subseq,candidates,target,0);
        return ans;
    }
};