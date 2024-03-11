#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        // count=s.size();
        string ans;
        for(int i=0;i<order.size();++i){
            for(int j=0;j<s.size();++j){
                if(order[i]==s[j]){
                    ans.push_back(order[i]);
                    s.erase(j);
                }
            }     
        }
        return ans+s;
    }
};

int main(){
    Solution s;
    cout<<s.customSortString("cba","abcd")<<endl;
}