class Solution {
public:
    string reverseVowels(string s) {
        string vowel = "aeiouAEIOU",temp = "";
        for(char c : s){
            if(vowel.find(c) != -1) temp.push_back(c);
        }
        int i = temp.size() - 1;
        for(char& c : s){
            if(vowel.find(c) != -1) c = temp[i--];
        }
        return s;
    }
};