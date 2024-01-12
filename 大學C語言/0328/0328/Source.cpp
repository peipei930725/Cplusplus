#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main() {
    int t, n, k, d;
    int arr[100] = { 0 };
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d %d", &n, &k, &d);
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
        }
        int sum[100] = { 0 }, count[101] = { 0 };
        for (int i = 0; (i + d - 1) < n; i++) {
            int count[101] = { 0 };

            for (int j = i; (j - i) < d; j++) {
                count[arr[j]]++;
            }
            for (int m = 1; m <= k; m++) {
                if (count[m] != 0) {
                    sum[i]++;
                }
            }
        }
        for (int i = 1; (i + d - 1) < n; i++) {
            if (sum[i] < sum[0]) {
                sum[0] = sum[i];
            }
        }
        printf("%d\n", sum[0]);
    }

    system("pause");
    return 0;

}