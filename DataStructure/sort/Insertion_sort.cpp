#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 把原本sort好的陣列再插入數字到適當的位置
void insertion_sort(int *arr,int n){
    for(int i=0;i<n;++i){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){//從sort好的陣列的尾端往前找到適當的位置
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main(){
    int arr[]={1,9,8,5,10,1,6,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr,n);

    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
}

