class Solution {
public:
    int minAddToMakeValid(string s) {
        int sz = 0,ans = 0;
        for(char i : s){
            if(i == '(') sz++;
            else sz--;
            if(sz < 0){
                sz++;
                ans++;
            }
        }
        return ans + sz;
    }
};