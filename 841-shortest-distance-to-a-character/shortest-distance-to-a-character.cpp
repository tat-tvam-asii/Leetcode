class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> indices,ans;
        for(int i = 0;i < s.size();i++) if(s[i] == c) indices.push_back(i);
        for(int i = 0;i < s.size();i++){
            if(s[i] == c){
                ans.push_back(0);
                continue;
            }
            int j = 0,mn = s.size();
            while(j < indices.size()){
                if(abs(indices[j]-i) < mn){
                    mn = abs(indices[j] - i);
                    j++;
                }
                else break;
            }
            ans.push_back(mn);
        }
        return ans;
    }
};