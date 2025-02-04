class Solution {
public:
    string decodeString(string s) {
        string ans;
        for(char c : s){
            if(c == ']'){
                string temp;
                while(ans.size() && ans.back() != '['){
                    temp += ans.back();
                    ans.pop_back();
                }
                ans.pop_back();
                reverse(temp.begin(),temp.end());
                string num;
                while(ans.size() && isdigit(ans.back())){
                    num += ans.back();
                    ans.pop_back();
                }
                reverse(num.begin(),num.end());
                for(int i = 0;i < stoi(num);i++) ans += temp;
            }
            else ans += c;
        }
        return ans;
    }
};