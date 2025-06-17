class Solution {
public:

    bool check(int I,int J,int n,vector<string>& temp){
        for(int i = I - 1,j = J - 1;i >= 0 && j >= 0;i--,j--) if(temp[i][j] == 'Q') return true;
        for(int i = I - 1,j = J + 1;i >= 0 && j < n;i--,j++) if(temp[i][j] == 'Q') return true;
        for(int i = 0;i < I;i++) if(temp[i][J] == 'Q') return true;
        return false;
    }

    void solve(vector<vector<string>>& ans,vector<string>& temp,int n,int i){
        if(i == n){
            ans.push_back(temp);
            return;
        }
        for(int j = 0;j < n;j++){
            if(check(i,j,n,temp)) continue;
            temp[i][j] = 'Q';
            solve(ans,temp,n,i+1);
            temp[i][j] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n,string(n,'.'));
        solve(ans,temp,n,0);
        return ans;
    }
};