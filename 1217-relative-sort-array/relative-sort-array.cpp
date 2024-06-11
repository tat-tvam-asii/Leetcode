class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        unordered_map<int,int> mp1,mp2;
        for(int i : arr1) mp1[i]++;
        for(int i : arr2) mp2[i]++;
        for(int i : arr1){
            if(!mp2[i]) ans.push_back(i);
        }
        sort(ans.begin(),ans.end(),greater<int>());
        reverse(arr2.begin(),arr2.end());
        for(int i : arr2){
            for(int j = 0;j < mp1[i];j++) ans.push_back(i);
        } 
        reverse(ans.begin(),ans.end());
        return ans;
    }
};