#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int stop=1;
        while(stop!=k || src!=dst){
            for(int i=0;i<size(flights);++i){
                if(flights[i][0]==src){
                    for(int j=0;j<size(flights);++j){
                        if(flights[j][0]==flights[i][1]){
                            flights[j][2]=flights[j][2]+flights[i][2];
                        }
                    }
                    src=flights[i][1];
                    
                    findCheapestPrice(n,flights,src,dst,k);
                }
            }
            ++k;
        }
        int cheapest=10000;
        for(int i=0;i<size(flights);++i){
            if(flights[i][0]==flights[i][1]){
                if(flights[i][2]<cheapest){
                    cheapest=flights[i][2];
                }
            }
        }
        if(cheapest!=10000){
            return cheapest;
        }
        else{
            return -1;
        }
    }
};


int main(){
    Solution s;
    vector<vector<int>> flights={{0,1,100},{1,2,100},{0,2,500}};
    cout<<s.findCheapestPrice(3,flights,0,2,1);
    return 0;
}