class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int n : arr) mp[(n % k + k) % k]++;
        for(auto&[a,b] : mp){
            if(((k-a) % k == a && mp[(k - a) % k] % 2 != 0) || (mp[(k - a) % k] != b)) return false;
        }
        return true;
    }
};