class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans,sorted = arr;
        sort(sorted.begin(),sorted.end());
        for(int i = arr.size()-1;i >= 0;i--){
            if(arr[i] == sorted[i]) continue;
            int j = i;
            while(arr[j] != sorted[i]) j--;
            reverse(arr.begin(),arr.begin()+j+1);
            ans.push_back(j+1);
            reverse(arr.begin(),arr.begin()+i+1);
            ans.push_back(i+1);
        }
        return ans;
    }
};