#include<iostream>
#include<string>
#include<vector>

using namespace std;

void dfs(vector<string>& a, vector<vector<int>>& weight, int i, int j, int& count){
    if(a[i-1][j-1]=='B'&&a[i+1][j-1]=='B'&&a[i][j]=='B'&&a[i-1][j+1]=='B'&&a[i+1][j+1]=='B'){

    }
    weight[i][j]=count;
    dfs(a,weight,i-1,j,count);
    dfs(a,weight,i+1,j,count);
    dfs(a,weight,i,j-1,count);
    dfs(a,weight,i,j+1,count);
}

int main(){
    int t=0;
    cin>>t;
    while(t--){
        vector<string> a(7);
        vector<vector<int>> weight(7,vector<int>(7,0));
        for(int i=0;i<6;++i){
            cin>>a[i];
        }
        for(int i=1;i<6;++i){
            for(int j=1;j<6;++j){
                if(a[i-1][j-1]=='B'&&a[i+1][j-1]=='B'&&a[i][j]=='B'&&a[i-1][j+1]=='B'&&a[i+1][j+1]=='B'){

                }
            }
        }
    }
}