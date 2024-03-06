#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    int t=0;
    cin>>t;
    while(t--){
        int n=0;
        cin>>n;
        vector<long long int> v;
        for(int i=0;i<n;++i){
            long long int reg=0;
            cin>>reg;
            v.push_back(reg);
        }
        for(int i=0;i<v.size();++i){
            for(int j=i;j<v.size();++j){
                if(v[i]+v[j]==2147483647){
                    v.erase(v.begin()+j);
                }
            }
        }
        cout<<v.size()<<endl;
    }
}