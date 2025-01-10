class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> mp;
        for(int i : nums) mp[i]++;
        int mx = 0,ans = -1;
        for(auto&[a,b] : mp){
            if(a%2 == 0){
                if(b > mx){
                    ans = a;
                    mx = b;
                }
            }
        }
        return ans;
    }
};