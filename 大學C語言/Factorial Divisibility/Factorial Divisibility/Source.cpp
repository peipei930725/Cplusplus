#include<stdio.h>
#include<stdlib.h>

int main() {
	int arr1[500] = { 0 };
	int arr2[500] = { 0 };	
	int case_num = 0;
	int max_num = 0;
	scanf_s("%d", &case_num);
	scanf_s("%d", &max_num);
	for (int i = 0; i < case_num; ++i) {
		scanf_s("%d", &arr1[i]);
		arr2[arr1[i]-1] ++;
	}
	for (int i = 0; i < max_num; ++i) {
		if (arr2[i] >= i + 2) {
			arr2[i + 1] = arr2[i + 1] + arr2[i] / (i + 2);
			arr2[i] = arr2[i] - (arr2[i] / (i + 2)) * arr2[i];
		}
		if (arr2[i] != 0) {
			printf("No");
			return 0;
		}
	}
	if (arr2[max_num - 1] >= 1) {
		printf("Yes");
		return 0;
	}
	printf("No");
	return 0;
}