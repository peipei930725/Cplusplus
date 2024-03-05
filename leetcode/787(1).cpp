#include<vector>
#include<string>
#include<iostream>
#include<queue>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int MAX=10001;

        vector<vector<int>> cost(n, vector<int>(2, MAX));

        for(int i=0;i<n;++i){
            cost[i][0]=i;
        }

        cost[src][1]=0;

        queue<int> nodes;
        nodes.push(src);

        int stop=0;
        while(!nodes.empty() && stop<=k){
            int count = nodes.size();
            for(int i=0;i<count;++i){
                int current = nodes.front();
                nodes.pop();
                for(const auto& flight : flights){
                    if(flight[0]==current){ //判斷起點是不是對的
                        if(cost[flight[0]][1]+flight[2]<cost[flight[1]][1]){ //判斷是不是最小
                            cost[flight[1]][1]=cost[flight[0]][1]+flight[2];
                            if(stop != k) { // 檢查是否已經達到最大停留次數
                                nodes.push(flight[1]);
                            }
                        }
                    }
                }
            }
            stop++;
        }

        return cost[dst][1]==MAX ? -1 : cost[dst][1];
    }
};

int main(){
    Solution s;
    vector<vector<int>> flights={{0,1,100},{1,2,100},{0,2,500}};
    cout<<s.findCheapestPrice(3,flights,0,2,1)<<endl;
    return 0;
}