#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int abss(int a){
    if(a<0){
        return -a;
    }
    return a;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> resident;
        int left=0,right=0;
        while(n--){
            int a;
            cin>>a;
            resident.push_back(a);
            right+=a;
        }
        int ans=0;
        int reg=resident.size()/2+1;
        for(int i=0;i<resident.size();i++){
            left+=resident[i];
            right-=resident[i];

            int test1=(i+1-left);
            int test2=(i+1/2);
            int test3=(right);
            int test4=((resident.size()-i)/2);

            if( (i+1-left) >= (i+1/2) && (right) >= ((resident.size()-i)/2) ){
                if(abss(i-(resident.size()/2 ))<reg){
                    reg=abss(i-(resident.size()/2 ));
                    ans=i+1;
                }
            }
        }
    }
    return 0;
}