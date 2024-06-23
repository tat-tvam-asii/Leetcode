class Solution {
public:
    int dp[2001][2001];
    
    bool isPalindrome(string& str,int i,int j){
        while(i <= j){
            if(str[i++] != str[j--]) return false;
        }
        return true;
    }

    int solve(string& str,int i,int j){
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(isPalindrome(str,i,j)) return 0;
        int mn = 1e9;
        for(int k = i;k < j;k++){
            if(isPalindrome(str,i,k)){
                int partitions = 1 + solve(str,k+1,j);
                if(partitions < mn) mn = partitions;
            }
        }
        return dp[i][j] = mn;
    }

    int minCut(string str)
    {
        memset(dp,-1,sizeof(dp));
        return solve(str,0,str.length()-1);
    }
};