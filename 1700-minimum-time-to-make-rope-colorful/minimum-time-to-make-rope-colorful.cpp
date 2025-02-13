class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int mx = 0,time = 0,ans = 0,i = 0,n = colors.size();
        while(i < n){
            mx = neededTime[i];
            time = mx;
            i++;
            while(i < n && colors[i] == colors[i-1]){
                time += neededTime[i];
                mx = max(mx,neededTime[i]);
                i++;
            }
            if(mx < time) ans += time - mx;
        }
        return ans;
    }
};