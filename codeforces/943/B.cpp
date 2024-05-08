#include <iostream>
#include <string>

using namespace std;

int max_subsequence_length(string a, string b) {
    int m = a.length(), n = b.length();
    int i = 0, j = 0;
    int max_len = 0, curr_len = 0;

    while (j < n) {
        if (j < n) {
            if(a[i] == b[j]){
                curr_len++;
                i++;
                j++;
            }
            else{
                j++;
            }
        } else {
            max_len = max(max_len, curr_len);
            curr_len = 0;
            j++;
            i = 0;  // 重置i回到字串a的開頭
        }
    }

    return max(max_len, curr_len);
}

int main() {
    int t;
    cin >> t;  // 輸入測試案例數量

    while (t--) {
        int n, m;
        cin >> n >> m;  // 輸入字串a和b的長度
        string a, b;
        cin >> a >> b;  // 輸入字串a和b
        cout << max_subsequence_length(a, b) << endl;  // 輸出最長子序列長度
    }

    return 0;
}