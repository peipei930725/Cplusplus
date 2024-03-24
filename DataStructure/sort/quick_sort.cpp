#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 使用divide and conquer的概念，把陣列分成兩半，再分成兩半，直到每個陣列只有一個數字
void quick_sort(int *arr,int n){
    if(n>1){
        int pivot=arr[n-1];
        int i=-1;
        for(int j=0;j<n-1;++j){
            if(arr[j]<pivot){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[n-1]);
        quick_sort(arr,i+1);
        quick_sort(arr+i+2,n-i-2);
    }
}
// 使用divide and conquer的概念，把陣列分成兩半，再分成兩半，直到每個陣列只有一個數字
// 選一個做為基準值，比基準值小的放左邊，比基準值大的放右邊
// 使用遞迴的方式(divide and conquer)，把陣列分成兩半，
// 再選一個做為基準值，分成兩邊，然後再分成兩半，
// 直到每個陣列只有一個數字 

int main(){
    int arr[]={1,9,8,5,10,1,6,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr,n);

    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
}

