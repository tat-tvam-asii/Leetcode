class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        int n = asteroids.size();
        int temp = 0;
        for(int i = n-1;i >= 0;i--){
            if(asteroids[i] < 0) st.push(-asteroids[i]);
            else{
                bool flag = false;
                while(!st.empty() && asteroids[i] >= st.top()){
                    if(st.top() == asteroids[i]){
                        st.pop();
                        flag = true;
                        break;
                    }
                    st.pop();
                }
                if(st.empty() && !flag) ans.push_back(asteroids[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        int i = 0;
        while(!st.empty()) ans.insert(ans.begin()+i++,-st.top()),st.pop();
        return ans;
    }
};