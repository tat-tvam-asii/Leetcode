class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        for(int i = 0;i < word.length();i++){
            string temp = "";
            temp += word[i];
            int cnt = 1;
            while(word[i] == word[i+1] && i < word.length()-1 && cnt < 9){
                temp += word[i];
                i++;
                cnt++;
            }
            ans += to_string(temp.length());
            ans += temp[0];
        }
        return ans;
    }
};