#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
char reg;
    int minimumLength(string s) {
        while(s[0]==s[s.size()-1]){
            if(s.size()==1) return 1;
            int count=0;
            reg=s[0];
            for(int i=0;i<s.size();++i){
                if(s[i]!=reg){
                    s.erase(0,i);
                    break;
                }
                count=i;
            }
            if(count==s.size()-1) return 0;
            if (s.empty()) return 0;
            for(int i=s.size()-1;i<s.size();--i){
                if(s[i]!=reg){
                    s.erase(i+1,s.size()-i);
                    break;
                }
            }
        }
        if (s.empty()) return 0;
        return s.size();
    }
};

int main(){
    Solution s;
    string str="b";
    cout<<s.minimumLength(str);
}