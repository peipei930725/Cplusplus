#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int count=0;
    unordered_map<int,int> hash;
    int big=0;
    long long countSubarrays(vector<int>& nums, int k) {
        int first=0,end=nums.size()-1;
        for(int i=0;i<nums.size();++i){
            if(nums[i]>big) big=nums[i];
            hash[nums[i]]++;
        }
        int a=hash[big];
        countingleft(nums,k,first,end);
        hash[big]=a;
        countingright(nums,k,first,end);

        return count;
    }
    void countingleft(vector<int>& nums, int k,int left,int right){ 
        if(k>hash[big] || left==right){
            return;
        }
        else{
            hash[nums[left]]--;
            count++;
            countingleft(nums,k,left+1,right);
        }
    }
    void countingright(vector<int>& nums, int k,int left,int right){ 
        if(k>hash[big] || left==right){
            return;
        }
        else{
            hash[nums[right]]--;
            count++;
            countingright(nums,k,left,right-1);
        }
    }
};

int main(){
    Solution s;
    vector<int> nums={61,23,38,23,56,40,82,56,82,82,82,70,8,69,8,7,19,14,58,42,82,10,82,78,15,82};
    cout<<s.countSubarrays(nums,2)<<endl;
    return 0;
}   