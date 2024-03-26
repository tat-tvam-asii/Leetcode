class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> op,cl;
        for(int i = 0;i < s.length();i++){
            if(s[i] == '(') op.push(i);
            else if(s[i] == ')'){
                if(!op.empty()) op.pop();
                else cl.push(i);
            }
        }
        while(!op.empty()){
            s.erase(s.begin() + op.top());
            op.pop();
        }
        while(!cl.empty()){
            s.erase(s.begin() + cl.top());
            cl.pop();
        }
        return s;
    }
};