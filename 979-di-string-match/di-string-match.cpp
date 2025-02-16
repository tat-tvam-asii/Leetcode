class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> ans;
        int n = s.size();
        int l = 0,h = n;
        if(s[0] == 'I') ans.push_back(l++);
        else ans.push_back(h--);
        for(int i = 0;i < n;i++){
            if(s[i] == 'I'){
                if(i + 1 < n && s[i+1] == 'D') ans.push_back(h--);
                else ans.push_back(l++);
            } 
            else{
                if(i + 1 < n && s[i+1] == 'I') ans.push_back(l++);
                else ans.push_back(h--);
            }
        }
        return ans;
    }
};