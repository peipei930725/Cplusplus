#include<iostream>
#include<vector>

using namespace std;

int plus1(int num){
    int hash1[200001]={0};
    if(hash1[num]!=0) return hash1[num];
    else{
        int sum=0;
        while(num!=0){
            sum+=num%10;
            num=num/10;
        }
        hash1[num]=sum;
        return sum;
    }

}

void calculate2(int num,int hash[]){
    int ans=0;
    for(int i=0;i<=num;++i){
        if(i>=10) ans+=plus1(i);
        else ans+=i;
        hash[i]=ans;
    }
}

void calculate(int num,int hash[]){
    // int ans=0;
    // for(int i=0;i<=num;++i){
    //     if(i>=10) ans+=plus1(i);
    //     else ans+=i;
    //     hash[i]=ans;
    // }
    cout<<hash[num]<<endl;
}

int main(){
    int hash[200001]={0};
    int t=0;
    cin>>t;
    calculate2(200000,hash);
    while(t--){
        int n=0;
        cin>>n;
        calculate(n,hash);
    }
    return 0;
}
