class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[] (int a,int b){
            string s1 = to_string(a),s2 = to_string(b);
            return s1+s2 > s2+s1;
        });
        string ans = "";
        for(int i : nums) ans += to_string(i);
        if(ans[0] == '0') return "0";
        return ans;
    }
};