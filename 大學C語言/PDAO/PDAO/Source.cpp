#include<iostream>

using namespace std;

int ident(char arr[], int num, int n) {
    int sum = 0;
    int count=0;
    for (int i = 0; i < num; ++i) {
        sum = sum + arr[i];
    }

    for (int i = num+1; i < n+1; ++i) {
        int plus = arr[i-1];
        while (plus <= sum || i < n + 1) {
            if (i > n + 1 && plus == sum)
                return 1;
            plus = plus + arr[i];
            ++i;
        }
        if (plus!=sum) {
            return 0;
        }
            
    }
    return 1;
}

int main() {
    int n = 0;
    cin >> n;
    char arr[100] = { 0 };
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; ++i) {
        arr[i] = arr[i] - 48;
    }
    if (arr[0] == arr[1] && arr[1] == 0 && n == 2) {
        cout << "YES" << endl;
        return 0;
    }
    for (int i = 1; i < n-1; ++i) {
        if (ident(arr, i, n-1) == 1) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}