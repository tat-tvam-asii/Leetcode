class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int>& subseq,set<vector<int>>& st,vector<int>& candidates,int target,int sum,int ind){
        if(sum == target){
            if(st.contains(subseq)) return;
            ans.push_back(subseq);
            st.insert(subseq);
            return;
        }
        if(ind == candidates.size()) return;
        if(sum + candidates[ind] > target) return;
        subseq.push_back(candidates[ind]);
        sum += candidates[ind];
        solve(ans,subseq,st,candidates,target,sum,ind);
        subseq.pop_back();
        sum -= candidates[ind];
        solve(ans,subseq,st,candidates,target,sum,ind+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subseq;
        set<vector<int>> st;
        sort(candidates.begin(),candidates.end());
        solve(ans,subseq,st,candidates,target,0,0);
        return ans;
    }
};