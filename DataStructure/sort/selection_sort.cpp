#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void selection_sort(int *arr,int n){
    for(int i=0;i<n;++i){
        int min=i;
        for(int j=i;j<n;++j){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}

int main(){
    int arr[]={1,9,8,5,10,1,6,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    selection_sort(arr,n);

    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
}

