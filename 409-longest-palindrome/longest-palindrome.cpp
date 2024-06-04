class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(char i : s) mp[i]++;
        int ans = 0;
        bool flag = false;
        for(auto[a,b] : mp){
            if(b % 2) flag = true;
            ans += (b - b%2);
        }
        if(flag) ans++;
        return ans;
    }
};