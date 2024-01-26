#include<vector>
#include<iostream>

using namespace std;

int main(){
    vector<int> arr[5];

    arr[0].push_back(0);
    arr[0].push_back(1);

    cout<<arr[0][1]<<endl;

    return 0;
}