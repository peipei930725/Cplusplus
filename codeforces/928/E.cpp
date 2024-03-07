#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int t=0;
    cin>>t;
    while(t--){
        vector<int> ans1;
        int n=0,k=0;
        cin>>n>>k;

        int count=0;
        int muti=1;
        while(count!=n){//1 3 5 7 2 6 10 3 9 15 4
            int num=1;
            while(num*muti<=n){
                ans1.push_back(num*muti);
                count++;
                if(count==n){
                    break;
                }
                num+=2;
            }
            muti++;
        }
        cout<<ans1[k-1]<<endl;
    }
    return 0;
}