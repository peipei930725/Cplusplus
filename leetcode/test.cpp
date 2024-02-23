#include<algorithm>
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (right > left) {
            right = right & (right - 1);
            cout<<right<<endl;
        }
        return right;
    }
};

int main(){
    Solution s;
    cout<<s.rangeBitwiseAnd(1,2147483647)<<endl;
    return 0;
}

// Example1:
// 5~7 maxmium is 100(4)
// their common bit is 100

//5~7 respective -4
//1~3 

//2~4 4~8 8~16 16~32