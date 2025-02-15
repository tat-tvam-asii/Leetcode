class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i = 0,j = tokens.size() - 1,score = 0;
        while(i <= j){
            if(tokens[i] <= power){
                power -= tokens[i];
                i++;
                score++;
            }
            else{
                if(score == 0 || i == j) break;
                power += tokens[j--];
                score--;
            }
        }
        return score;
    }
};