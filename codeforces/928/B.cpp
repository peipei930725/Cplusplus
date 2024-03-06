#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int t=0;
    cin>>t;
    while(t--){
        int n=0;
        vector<int> a;
        cin>>n;
        // vector<vector<int>> space;
        for(int i=0;i<n;++i){
            int count=0;
            string in;
            cin>>in;
            for(int i=0;i<in.size();++i){
                if(in[i]=='1') count++;
            }
            
            if(count!=0) a.push_back(count);
        }
        if(a[0]==a[1]) cout<<"SQUARE"<<endl;
        else cout<<"TRIANGLE"<<endl;
    }
    return 0;
}