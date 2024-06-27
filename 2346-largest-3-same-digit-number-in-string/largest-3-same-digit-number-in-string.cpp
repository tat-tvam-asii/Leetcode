class Solution {
public:
    string largestGoodInteger(string num) {
        int mx = -1;
        for(int i = 0;i < num.length()-2;i++){
            string sub = num.substr(i,3);
            if(sub[0] == sub[1] && sub[1] == sub[2]){
                mx = max(mx,stoi(sub));
            }
        }
        if(mx == -1) return "";
        if(mx == 0) return "000";
        return to_string(mx);
    }
};