class Solution {
public:
    bool solve(int ind,vector<int>& ans,vector<bool>& isUsed,int n){
        if(ind == ans.size()) return true;

        if(ans[ind] != 0){
            return solve(ind+1,ans,isUsed,n);
        }

        for(int i = n;i >= 1;i--){
            if(isUsed[i]) continue;
            isUsed[i] = true;
            ans[ind] = i;

            if(i == 1){
                if(solve(ind+1,ans,isUsed,n)) return true;
            }
            else if(ind+i < ans.size() && ans[ind+i] == 0){
                ans[ind+i] = i;
                if(solve(ind+1,ans,isUsed,n)) return true;
                ans[ind+i] = 0;
            }
            ans[ind] = 0;
            isUsed[i] = false;
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        int size = 2*n - 1;
        vector<int> ans(size,0);
        vector<bool> isUsed(n+1,false);
        if(solve(0,ans,isUsed,n)) return ans;
        return ans;
    }
};