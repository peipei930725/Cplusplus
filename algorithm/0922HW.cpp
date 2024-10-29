#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums = {19, 29, 2, 27, 3, 23, 5, 9, 8, 0};

    for(int i=1;i<nums.size();i++){
        for(int j=i;j>0;j--){
            if(nums[j]<nums[j-1]){
                swap(nums[j],nums[j-1]);
            }
        }
    }

    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }

    return 0;
}