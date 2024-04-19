#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int big=0;
        long long ans=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]>big) big=nums[i];
        }
        for(int i=0,count=0,l=0;i<nums.size();++i){
            if(nums[i]==big){
                count++;
                if(count>=k){
                    l=count;
                    int j=0;
                    while(l>=k){
                        ans++;
                        if(nums[j]==big) l--;
                        j++;
                    }
                    
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums={61,23,38,23,56,40,82,56,82,82,82,70,8,69,8,7,19,14,58,42,82,10,82,78,15,82};
    cout<<s.countSubarrays(nums,2)<<endl;
    return 0;
}