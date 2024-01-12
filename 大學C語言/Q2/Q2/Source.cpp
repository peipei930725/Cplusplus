#include<stdio.h>
#include<stdlib.h>

int main() {
	int datalist = 0;
	scanf_s("%d", &datalist);
	for (int i = 0; i < datalist; ++i) {
		int arr[500] = { 0 };
		int arr_len = 0;
		scanf_s("%d", &arr_len);
		for (int j = 0; j < arr_len; ++j) {
			scanf_s("%d", &arr[j]);
		}
		for (int m = 0; m < arr_len; ++m) {
			for (int n = 1; n < arr_len - m; ++n) {
				if (arr[n-1] > arr[n]) {
					int temp = arr[n];
					arr[n] = arr[n-1];
					arr[n-1] = temp;
				}
			}
		}
		int x = (arr_len+1)/ 2;
		int sum = 0, y = 0;
		for (int j = 0; j < arr_len; ++j) {
			y = arr[x-1] - arr[j];
			y = y >= 0 ? y : -y;
			sum = sum + y;
		}
		printf("%d\n", sum);
	}
	return 0;
}