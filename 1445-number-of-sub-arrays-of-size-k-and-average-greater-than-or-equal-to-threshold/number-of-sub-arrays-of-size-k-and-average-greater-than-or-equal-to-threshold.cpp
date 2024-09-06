class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i = 0,j = 0,n = arr.size(),sum = 0,ans = 0;
        while(j < n){
            sum += arr[j++];
            if(j - i > k) sum -= arr[i++];
            if(j - i == k && sum >= k*threshold) ans++;
        }
        return ans;
    }
};