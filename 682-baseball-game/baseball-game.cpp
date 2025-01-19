class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(string s : operations){
            if(s == "+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a+b);
            }
            else if(s == "D"){
                int a = st.top();
                st.push(2*a);
            }
            else if(s == "C") st.pop();
            else{
                int a = stoi(s);
                st.push(a);
            }
        }
        int sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};