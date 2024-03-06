#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int max=0;
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());

        if(tokens.empty()) return 0;

        return dp(tokens,power);
    }
    int dp(vector<int>& tokens, int power) {
        if (power < tokens[0] || tokens.empty()) {
            return max;
        } 
        else {
            int sum = 0;
            for (int i = 0; i < tokens.size(); ++i) {
                sum += tokens[i];
                if (power >= sum) {
                    if(i>max) max=i+1;
                } 
            }
            if (power > sum) {
                return max;
            } 
            power-=tokens[0];
            tokens.erase(tokens.begin()); 
            power+=tokens[tokens.size()];
            tokens.pop_back();
            return dp(tokens, power);
        }
    }
};

int main(){
    Solution s;
    vector<int> tokens={17,47,41,57,51};
    int power=31;
    cout<<s.bagOfTokensScore(tokens,power);
}