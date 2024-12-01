class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,bool> mp;
        sort(arr.begin(),arr.end(),[&](int a,int b){
            return abs(a) > abs(b);
        });
        for(int i : arr){
            if(mp[2*i]) return true;
            mp[i] = true;
        }
        return false;
    }
};