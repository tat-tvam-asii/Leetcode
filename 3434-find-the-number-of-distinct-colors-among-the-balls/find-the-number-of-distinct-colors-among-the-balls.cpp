class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> mp,colormp;
        vector<int> ans;
        for(auto it : queries){
            if(mp[it[0]]){
                if(--colormp[mp[it[0]]] == 0) colormp.erase(mp[it[0]]);
                colormp[it[1]]++;
                mp[it[0]] = it[1];
            }
            else{
                colormp[it[1]]++;
                mp[it[0]] = it[1];
            }
            ans.push_back(colormp.size());
        }
        return ans;
    }
};