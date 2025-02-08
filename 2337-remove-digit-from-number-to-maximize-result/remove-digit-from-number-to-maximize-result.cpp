class Solution {
public:
    string removeDigit(string number, char digit) {
        for(int i = 0;i < number.size() - 1;i++){
            if(number[i] < number[i+1] && number[i] == digit){
                number.erase(number.begin() + i);
                return number;
            }
        }
        for(int i = number.size() - 1;i >= 0;i--){
            if(number[i] == digit){
                number.erase(number.begin() + i);
                return number;
            }
        }
        return number;
    }
};