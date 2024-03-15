class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        vector<string> ans;
        for(int i=0;i<arr.size();i++){
            string minsub = arr[i];
            bool occ = false;
            for(int j=0;j<arr[i].size();j++){
                for(int k=1;k<=arr[i].size()-j;k++){
                    string sub = arr[i].substr(j,k);
                    bool flag = true;
                    for(int l=0;l<arr.size();l++){
                        if(l != i && arr[l].find(sub) != -1){
                            flag = false;
                            break;
                        }
                    }
                    if(flag){ 
                        occ = true;
                        if(minsub.length() > sub.length()) minsub = sub;
                        else if(minsub.length() == sub.length()) minsub = min(minsub,sub);
                    }
                }
            }
            if(occ) ans.push_back(minsub);
            else ans.push_back("");
        }
        return ans;
    }
};