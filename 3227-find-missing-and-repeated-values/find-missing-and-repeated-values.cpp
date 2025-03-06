class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,bool>mp;
        int a,b,n = grid.size(),sum = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!mp[grid[i][j]]){
                    mp[grid[i][j]] = true;
                    sum += grid[i][j];
                }
                else a = grid[i][j];
            }
        }
        b = (n*n)*(n*n + 1)/2 - sum;
        return {a,b}; 
    }
};