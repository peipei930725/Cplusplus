#include<iostream>

using namespace std;

int main(){
    int t=0;
    cin>>t;
    while(t--){
        long long int n,x,y,s;
        long long int sum=1;
        cin>>n>>x>>y>>s;
        long long int arr[100000]={0};
        for(int i=0;i<n;++i){
            cin>>arr[i];
        }
        for(int i=0;i<n;++i){
            sum=sum*arr[i];
        }
        if(s>y){
            int count=0;
            s=s-y;
            count=s/(x+y);
            count=count+1;
            if(count<sum){
                cout<<sum<<endl;
            }
            else{
            cout<<count<<endl;
            }      
        }  
        else{
            cout<<"0"<<endl;
        }
    }
    return 0;
}