#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

/*int increasing(int arr[], int num) {
	int i = 1;
	while (arr[i - 1] < arr[i]) {
		++i;
	}
	return i - 1;
}
void decreasing(int arr[], int num, int cord) {
	for (int i = cord + 1; i < num; ++i) {
		if (arr[i - 1] < arr[i]);
		else {
			printf("Yes\n");
			return;
		}
	}
	printf("No\n");
	return;
}*/

int main() {
	int t = 0;
	scanf("%d", &t);
	while (t--) {
		int n = 0, record = n+1, p = 0;
		bool flag = true;
		scanf("%d", &n);
		int arr[3000] = { 0 };
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &arr[i]);
		}
		for (int i = 1; i <= n; ++i) {
			if (arr[i] < i-1) {
				record = i;
				p = arr[i - 1];
				break;
			}
			record = i;
		}
		for (int i = record; i <= n; ++i) {//decreasing
			if(arr[i]<p){
				p = arr[i];
			}
			else {
				if (p - 1 >= 0) {
					p--;
				}
				else {
					flag = false;
					break;
				}
			}
		}
		flag ? printf("Yes\n") : printf("No\n");
	}
	return 0;
}