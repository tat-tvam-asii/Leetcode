class Solution {
public:
    int maxRec(vector<int>& arr){
        int n = arr.size();
        stack<int> str;
        vector<int> nsr(n);
        for(int i = n-1;i >= 0;i--){
            while(!str.empty() && arr[str.top()] >= arr[i]) str.pop();
            if(str.empty()) nsr[i] = n;
            else nsr[i] = str.top();
            str.push(i);
        }
        stack<int> stl;
        vector<int> nsl(n);
        for(int i = 0;i < n;i++){
            while(!stl.empty() && arr[stl.top()] >= arr[i]) stl.pop();
            if(stl.empty()) nsl[i] = -1;
            else nsl[i] = stl.top();
            stl.push(i);
        }
        int ans = 0;
        for(int i = 0;i < n;i++){
            ans = max(ans,arr[i]*(nsr[i] - nsl[i] - 1));
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        int ans = 0;
        for(int j = 0;j < n;j++){
            vector<int> arr(m);
            for(int i = 0;i < m;i++){
                int cnt = 0;
                for(int k = j;k < n;k++){
                    if(matrix[i][k] == '0') break;
                    cnt++;
                }
                arr[i] = cnt;
            }
            ans = max(ans,maxRec(arr));
        }
        return ans;
    }
};