#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int GCD(int a, int b){
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int LCM(int a, int b){
    return (a * b) / GCD(a, b);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        LCM(a,b)

    }
    return 0;
}