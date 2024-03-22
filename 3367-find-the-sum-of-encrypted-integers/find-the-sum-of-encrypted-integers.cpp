class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans = 0;
        for(int i : nums){
            string s = to_string(i);
            char mx = *max_element(s.begin(),s.end());
            string temp = string(s.size(),mx);
            ans += stoi(temp);
        }
        return ans;
    }
};