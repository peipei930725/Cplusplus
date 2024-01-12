#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

void sort(int arr1[],int i,int count) {
	for (int a = i - count+1; a <= i; ++a) {
		for(int j = i - count + 1; j <= i - a; j++) {
			if (arr1[i - count - 1] > arr1[i - count]) {
				int temp = arr1[i - count - 1];
				arr1[i - count - 1] = arr1[i - count];
				arr1[i - count] = temp;
			}
		}
	}
}
void verify(int arr1[],int len) {
	for (int i = 1; i < len; ++i) {
		if (arr1[i - 1] > arr1[i]) {
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}

int main() {
	int t = 0;
	scanf("%d", &t);
	while (t--) {
		int n = 0, m = 0;
		scanf("%d %d", &n, &m);
		int sorting[100] = { 0 };
		int arr1[100] = { 0 }, arr2[100] = { 0 };
		for (int i = 0; i < n; ++i) {
			scanf("%d", &arr1[i]);
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d", &arr2[i]);;
		}
		for (int i = 1; i < m; ++i) {
			int count = 1;
			if (arr2[i - 1] + 1 == arr2[i]) {
				count++;
				++i;
				while (arr2[i - 1] + 1 == arr2[i]) {
					count++;
					++i;
				}
				sort(arr1, i , count);
			}
			else
				sort(arr1, i - 1, 1);
		}
		verify(arr1, n);
	}
	system("pause");
	return 0;
}