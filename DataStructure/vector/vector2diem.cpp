#include<vector>
#include<iostream>

using namespace std;

int main(){
    vector<vector<int>> v(2);
 
    v={
        {1,2},
        {3,4}
    };

    cout<<v[0][0]<<endl;

    return 0;
}