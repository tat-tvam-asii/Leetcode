class Solution {
public:
    bool solve(string& s,string& p,int i,int j){
        if(i < 0){
            while(j > 0 && p[j] == '*') j -= 2;
            return j < 0;
        }
        if(j < 0) return i < 0;
        if(p[j] == '*') return solve(s,p,i,j-1);
        if(s[i] == p[j]){
            if(j < p.length() - 1 && p[j+1] == '*') return solve(s,p,i-1,j-1) || solve(s,p,i-1,j) || solve(s,p,i,j-1);
            else return solve(s,p,i-1,j-1);
        }
        else{
            if(p[j] == '.' && j < p.length() - 1 && p[j+1] == '*') return solve(s,p,i-1,j-1) || solve(s,p,i-1,j) || solve(s,p,i,j-1);
            else if(p[j] == '.') return solve(s,p,i-1,j-1);
            else if(j < p.length() - 1 && p[j+1] == '*') return solve(s,p,i,j-1);
            else return false;
        }
    }

    bool isMatch(string s, string p) {
        int m = s.length(),n = p.length();
        return solve(s,p,m-1,n-1);
    }
};