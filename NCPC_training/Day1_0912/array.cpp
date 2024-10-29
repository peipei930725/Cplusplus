#include<iostream>
#include<algorithm>
#include<array>
#include<vector>

using namespace std;

int main(){
    int arr[5]={};
    vector<int> vec={};
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    cout<<vec.size()<<endl;//*****

    size_t size = sizeof(arr)/sizeof(int);
    cout<<size<<endl;
}

// 使用指針算術: *****
// int arr[] = {1, 2, 3, 4, 5};
// int* ptr = arr;
// cout << *(ptr + 2) << endl;  // 輸出第三個元素

// 數組作為函數參數: ****
// void printArray(int arr[], int size);
// void printArray(int* arr, int size);

// 使用std::copy和std::fill: ***
// #include <algorithm>
// int source[] = {1, 2, 3, 4, 5};
// int dest[5];
// std::copy(std::begin(source), std::end(source), dest);
// std::fill(std::begin(dest), std::end(dest), 0);  // 填充為0