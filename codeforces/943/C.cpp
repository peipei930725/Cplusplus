#include<iostream>

using namespace std;

int main(){
    int t=0;
    cin>>t;
    while(t--){
<<<<<<< HEAD
        
    }
=======
        int n=0;
        cin>>n;
        int ans[n];
        n--;
        int a[n];
        for(int i=0;i<n;++i){
            cin>>a[i];
        }
        ans[0]=a[0]+1;
        for(int i=1;i<n+1;++i){
            if(a[i-1]>ans[i-1]){
                i--;
                ans[i]=a[i-1]+ans[i-1]*(a[1]/ans[i-1]+1);
            }
            else{ 
                ans[i]=a[i-1]+ans[i-1];
            }
        }
        for(int i=0;i<n+1;++i){
            cout<<ans[i]<<" ";
        }
    }
    return 0;
>>>>>>> 6d42599c73be1b8b0396bea4b6053e98710bacf9
}