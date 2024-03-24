#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        int tent=0;
        cin>>a>>b>>c;
        tent+=a;
        if((b+c)%3==0){
            cout<<tent+(b+c)/3<<endl;
        }
        else{
            if(b%3==1 && c<2){
                cout<<-1<<endl;
            }
            else if(b%3==2 && c<1){
                cout<<-1<<endl;
            }
            else{
                cout<<tent+(b+c)/3 +1<<endl;
            }
        }

    }
    return 0;
}