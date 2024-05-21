#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
  vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
    const int n = A.size();
    double l = 0;
    double r = 1.0;    
    while (l < r) {
      double m = (l + r) / 2; //設中間點
      double max_f = 0.0;
      int total = 0;
      int p, q = 0;
      for (int i = 0, j = 1; i < n - 1; ++i) {
        while (j < n && A[i] > m * A[j]) ++j;              //找到分數小於等於m的分數 這邊是用雙指針
        if (n == j) break;
        total += (n - j);                                  //計算有多少個分數小於等於m 他會爆出來 那就會再更新中點 找到最大的分數
        const double f = static_cast<double>(A[i]) / A[j]; //找最大的分數
        if (f > max_f) {
          p = i;
          q = j;
          max_f = f;
        }
      }
      if (total == K)   //如果一樣就輸出最大的
        return {A[p], A[q]};        
      else if (total > K) //不一樣就繼續二分搜尋 更新中點
        r = m;
      else
        l = m;
    }
    return {};
  }
};