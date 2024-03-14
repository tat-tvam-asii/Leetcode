class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i = 0,j = 0,l = s.length(),k = p.length();
	    int arr[26] = {0};
	    vector<int> ans;
	    for(char i : p) arr[i-'a']++;
	    while(j < l){
	        arr[s[j]-'a']--;
	        if(j-i+1 == k){
	            bool flag = true;
	            for(int i=0;i<26;i++){
	                if(arr[i]) flag = false;
	            }
	            if(flag) ans.push_back(i);
	            arr[s[i]-'a']++;
	            i++;
	        }
	        j++;
	    }
	    return ans;
    }
};