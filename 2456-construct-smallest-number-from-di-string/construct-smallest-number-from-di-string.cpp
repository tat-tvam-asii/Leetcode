class Solution {
public:
    bool solve(string& pattern,vector<int>& isUsed,string& temp){
        int n = pattern.size();
        if(temp.size() == n+1) return true;
        
        for(int i = 1;i <= n+1;i++){
            if(isUsed[i]) continue;
            if(temp.size()){
                int sz = temp.size() - 1;
                if(pattern[sz] == 'I' && i <= temp.back() - '0') continue;
                if(pattern[sz] == 'D' && i >= temp.back() - '0') continue;
            }
            isUsed[i] = 1;
            temp.push_back('0' + i);
            if(solve(pattern,isUsed,temp)) return true;
            temp.pop_back();
            isUsed[i] = 0;
        }
        return false;
    }

    string smallestNumber(string pattern) {
        int n = pattern.size();
        vector<int> isUsed(n+2,0);
        string temp = "";
        if(solve(pattern,isUsed,temp)) return temp;
        return "";
    }
};