#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void bubble_sort(int *arr,int n){
    for(int i=0;i<n;++i){
        for(int j=0;j<n-i;++j){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main(){
    int arr[]={1,9,8,5,10,1,6,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> v={5,3,10,4,7};
    // bubble_sort(arr,n);
    sort(arr,arr+n);
    sort(v.begin(),v.end());

    for(int i=0;i<v.size();++i){
        cout<<v[i]<<" ";
    }
}