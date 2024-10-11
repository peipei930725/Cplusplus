#include<iostream>
#include<vector>

using namespace std;

int solve(int during_time,int start,vector <int> b,vector <int> s){
    int t=during_time;
    int score=s[b[start]];
    cout<<score<<endl;
    while(t--){
        if(s[b[start]]<s.size()){
            if(s[b[start]]<=s[b[s[b[start]]]]){
                score+=s[b[s[b[start]]]];
                start=s[b[start]];
                cout<<score<<endl;
            }
            else{
                score+=s[b[start]];
                start=s[b[s[b[start]]]];
                cout<<score<<endl;
            }
        }
        else{
            score+=s[b[start]];
            start=s[b[s[b[start]]]];
            cout<<score<<endl;
        }
    }
    return score;
}

int main(){
    int t=0;
    cin>>t;
    while(t--){
        int n,k,pb,ps;
        cin>>n>>k>>pb>>ps;
        vector<int> b(n),s(n);
        for(int i=0;i<n;++i){
            int x;
            cin>>x;
            b[i]=x;
        }
        for(int i=0;i<n;++i){
            int x;
            cin>>x;
            s[i]=x;
        }
        int scoreB=0,scoreS=0;
        scoreB=solve(k,pb,b,s);
        scoreS=solve(k,ps,s,b);
        if(scoreB>scoreS){
            cout<<"Bodya"<<endl;
        }
        else if (scoreB<scoreS){
            cout<<"Sasha"<<endl;
        }
        else{
            cout<<"Draw"<<endl;
        }
    }
    return 0;
}