class Solution {
public:
    void solve(vector<string>& vs,int& n,string temp){
        if(temp.size() == n){
            vs.push_back(temp);
            return;
        }
        string s = "abc";
        for(char c : s){
            if(!temp.empty() && temp.back() == c) continue;
            temp.push_back(c);
            solve(vs,n,temp);
            temp.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        vector<string> vs;
        solve(vs,n,"");
        if(vs.size() < k) return "";
        return vs[k-1];
    }
};