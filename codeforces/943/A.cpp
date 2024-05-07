#include<iostream>

using namespace std;

int gcd(int a,int b){
    int temp;
    while(b != 0){
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
};

int main(){
    int input=0;
    int max=0;
    int ans=0;
    int t=0;
    cin>>t;
    while(t--){
        cin>>input;
        max=0;
        ans=0;
        for(int i=1;i<input;++i){
            if((gcd(input,i)+i)>max){
                max=gcd(input,i)+i;
                ans=i;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}