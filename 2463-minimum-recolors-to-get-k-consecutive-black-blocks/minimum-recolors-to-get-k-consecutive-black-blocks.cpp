class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length(),mn = n,sum = 0,i = 0,j = 0;
        for(j = 0;j < n;j++){
            sum += blocks[j] == 'W';
            if(j - i + 1 == k){
                mn = min(mn,sum);
                sum -= blocks[i++] == 'W';
            }
        }
        return mn;
    }
};