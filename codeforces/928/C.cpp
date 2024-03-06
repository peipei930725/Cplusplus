#include<iostream>
#include<vector>

using namespace std;

int plus1(int num){
    int hash[200001]={0};
    if(hash[num]!=0) return hash[num];
    else{
        int sum=0;
        while(num!=0){
            sum+=num%10;
            num=num/10;
        }
        hash[num]=sum;
        return sum;
    }

}

void calculate(int num){
    int ans=0;
    for(int i=0;i<=num;++i){
        if(i>=10) ans+=plus1(i);
        else ans+=i;
    }
    cout<<ans<<endl;
}

int main(){
    int t=0;
    cin>>t;
    while(t--){
        int n=0;
        cin>>n;
        calculate(n);
    }
    return 0;
}
