class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n1 = words1.size(),n2 = words2.size();
        vector<vector<int>> cnt1(n1,vector<int>(26,0));
        vector<vector<int>> cnt2(26,vector<int>(n2,0));
        for(int i = 0;i < n1;i++){
            for(char c : words1[i]){
                cnt1[i][c-'a']++;
            }
        }
        for(int i = 0;i < n2;i++){
            for(char c : words2[i]){
                cnt2[c-'a'][i]++;
            }
        }
        vector<int> mx(26,0);
        for(int i = 0;i < 26;i++) mx[i] = *max_element(cnt2[i].begin(),cnt2[i].end());
        vector<string> ans;
        for(int i = 0;i < n1;i++){
            bool flag = true;
            for(int j = 0;j < 26;j++){
                if(mx[j] > cnt1[i][j]){
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(words1[i]);
        }
        return ans;
    }
};