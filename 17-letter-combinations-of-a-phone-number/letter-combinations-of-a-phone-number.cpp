class Solution {
public:
    void solve(string& digits,vector<string>& ans,int i){
        if(i == digits.length()){
            if(!digits.empty()) ans.push_back(digits);
            return;
        }
        int x = 3* (digits[i] - '0' - 2);
        if(x == 18 || x == 21) x++;
        int a = 3;
        if(digits[i] == '7' || digits[i] == '9') a++;
        for(int j = x;j < x+a;j++){
            char temp = digits[i];
            digits[i] = (char)('a' + j);
            solve(digits,ans,i+1);
            digits[i] = temp;
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        solve(digits,ans,0);
        return ans;
    }
};