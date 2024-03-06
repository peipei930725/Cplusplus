#include<iostream>
#include<string>

using namespace std;

void count(string &input,string &ans){
    int a=0;
    for(int i=0;i<5;++i){
        if(input[i]=='A'){
            a++;
        }
    }
    if(a>(5-a)) ans.push_back('A');
    else ans.push_back('B');
}

int main(){
    int t=0;
    string ans;
    cin>>t;
    while(t--){
        string a;
        cin>>a;
        count(a,ans);      
    }
    for(int i=0;i<ans.size();++i){
        cout<<ans[i]<<endl;
    }

    return 0;
}
