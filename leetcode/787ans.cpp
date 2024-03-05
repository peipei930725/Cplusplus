#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        const int MAX = 1e9;
        vector<int> dp(n, MAX);  //花費表
        dp[src] = 0;
        for(int k = 0; k <= K; k++) {
            vector<int> dp1 = dp;
            for(auto& e : flights) {
                int a = e[0], b = e[1], c = e[2];
                dp1[b] = min(dp1[b], dp[a] + c);  //更新花費表
            }
            dp = dp1;
        }
        return dp[dst] == MAX ? -1 : dp[dst];
    }
};



int main(){
    Solution s;
    vector<vector<int>> flights={{0,1,100},{1,2,100},{0,2,500}};
    cout<<s.findCheapestPrice(3,flights,0,2,1);
    return 0;
}