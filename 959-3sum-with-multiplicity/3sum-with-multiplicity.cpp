class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod = 1e9 + 7;
        sort(arr.begin(),arr.end());
        int n = arr.size(),ans = 0;
        for(int i = 0;i < n;i++){
            int j = i+1,k = n-1;
            while(j < k){
                int total = arr[i] + arr[j] + arr[k];
                if(total > target) k--;
                else if(total < target) j++;
                else{
                    if(arr[j] == arr[k]){
                        int dist = k - j + 1;
                        ans = (ans % mod  + ((dist * (dist-1))/2) % mod) % mod;
                        j = k;
                        continue;
                    }
                    int cntj = 1,cntk = 1;
                    while(j+1 < k && arr[j] == arr[j+1]) cntj++,j++;
                    while(k-1 > j && arr[k] == arr[k-1]) cntk++,k--;
                    ans = (ans % mod + (cntj * cntk) % mod) % mod;
                    j++;
                    k--;
                }
            }
        }
        return ans;
    }
};