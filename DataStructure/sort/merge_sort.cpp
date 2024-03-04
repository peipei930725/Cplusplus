#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 使用divide and conquer的概念，把陣列分成兩半，再分成兩半，直到每個陣列只有一個數字
void merge_sort(int *arr,int n){
    if(n>1){
        int mid=n/2;
        int *L=new int[mid];
        int *R=new int[n-mid];

        for(int i=0;i<mid;++i){
            L[i]=arr[i];
        }
        for(int i=mid;i<n;++i){
            R[i-mid]=arr[i];
        }

        merge_sort(L,mid);
        merge_sort(R,n-mid); // recall回去merge_sort，直到每個陣列只有一個數字
        //分到最底層後，最底層的先merge，再往上一層merge，直到最上層
        int i=0,j=0,k=0; 
        while(i<mid && j<n-mid){
            if(L[i]<R[j]){ //比較兩個陣列的第一個數字，小的放前面，開始合併
                arr[k]=L[i];
                i++;
            }else{
                arr[k]=R[j];
                j++;
            }
            k++;
        }
        //當兩個比較完後，剩下的數字直接放到arr後面
        while(i<mid){
            arr[k]=L[i];
            i++;
            k++;
        }
        while(j<n-mid){
            arr[k]=R[j];
            j++;
            k++;
        }
    }
}

int main(){
    int arr[]={1,9,8,5,10,1,6,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr,n);

    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
}

