#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=1;
        int ans;
        for(int i=0;i<nums.size();++i){
            while(i < nums.size() && nums[i] <= 0){
                ++i;
            }
            if(i < nums.size() && nums[i] != count) return count;
            else ++count;
        }
        return nums[nums.size()-1]+1;
    }
};

int main(){
    Solution s;
    vector<int> nums={0};
    cout<<s.firstMissingPositive(nums)<<endl;
    return 0;
}