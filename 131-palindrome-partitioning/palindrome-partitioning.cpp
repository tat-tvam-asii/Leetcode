class Solution {
public:
    bool isPalindrome(string s,int st,int en){
        while(st <= en) if(s[st++] != s[en--]) return false;
        return true;
    }

    void solve(vector<vector<string>>& ans,vector<string>& path,string s,int ind){
        if(ind == s.size()){
            ans.push_back(path);
            return;
        }
        for(int i = ind;i < s.size();i++){
            if(isPalindrome(s,ind,i)){
                path.push_back(s.substr(ind,i - ind + 1));
                solve(ans,path,s,i+1);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(ans,path,s,0);
        return ans;
    }
};