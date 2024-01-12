#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int fib(int n) {
        vector<int> v;
        v.push_back(0);
        v.push_back(1);
        for(int i=0;i<n-1;++i){
            v.push_back(v[i]+v[i+1]);
        }
        return v[n];
    }
};
int main(){
    Solution ans;
    cout<<ans.fib(2)<<endl;

    return 0;
}