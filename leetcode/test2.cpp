#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='1'){
                count++;
                s[i]='0';
            }
        }
        for(int i=0;i<s.size();++i){
            if(count>1){
                s[i]='1';
                count--;
            }
        }
        s[s.size()-1]='1';

        return s;
    }
};

int main(){
    Solution s;
    cout<<s.maximumOddBinaryNumber("010");
    return 0;
}