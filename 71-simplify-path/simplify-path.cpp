class Solution {
public:
    string simplifyPath(string path) {
        stack<char> st;
        for(int i = 0;i < path.length();i++){
            if(path[i] == '/'){
                if(st.empty()) st.push('/');
                else if(i < path.length() - 1 && st.top() != '/') st.push('/');
            }
            else if(path[i] == '.'){
                string temp = ".";
                i++;
                while(i < path.length() && path[i] != '/') temp += path[i++];
                if(temp == ".." && st.top() == '/'){
                    if(st.size() != 1){
                        st.pop();
                        while(!st.empty() && st.top() != '/') st.pop();
                        if(st.size() > 1) st.pop();
                    }
                }
                else if(!(st.top() == '/' && temp == ".")){
                    for(char c : temp) st.push(c);
                }
                i--;
            }
            else st.push(path[i]);
        }
        while(!st.empty() && st.size() != 1 && st.top() == '/') st.pop();
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};