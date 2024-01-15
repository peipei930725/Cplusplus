#include<iostream>
using namespace std;

int bsearch(int num){
    int arr[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    if(num < arr[0] || num > arr[9]){
        cout << "Not found" << endl;
        return -1;
    }
    int left = 0, right = 9;
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] == num){
            cout << "Found ";
            return mid;
        }
        else if(arr[mid] > num){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    cout << "Not found" << endl;
    return -1;
}

int main(){

    bsearch(6);
    cout << "the index of num is " << bsearch(6) << endl;

    return 0;
}