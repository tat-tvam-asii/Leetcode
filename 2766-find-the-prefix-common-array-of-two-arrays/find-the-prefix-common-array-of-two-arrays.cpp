class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> mp;
        vector<int> ans(A.size(),0);
        ans[0] = (A[0] == B[0]);
        mp[A[0]]++;
        mp[B[0]]++;
        for(int i = 1;i < A.size();i++){
            ans[i] = ans[i-1];
            if(mp[A[i]]) ans[i] += 1;
            mp[A[i]]++;
            if(mp[B[i]]) ans[i] += 1;
            mp[B[i]]++;
        }
        return ans;
    }
};