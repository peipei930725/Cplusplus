#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main() {
	int n = 0, divid[129] = { 0 }, arr1[129] = { 0 }, max=0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {	//input
		scanf("%d", &divid[i]);
	}
	for (int i = 1; i < n; ++i) {	//sort ¤j¨ì¤p
		for (int j = 1; j <= n-i; ++j) {
			if (divid[j - 1] < divid[j]) {
				int temp = divid[j - 1];
				divid[j - 1] = divid[j];
				divid[j] = temp;
			}
		}
	}
	for (int i = 1; i < n; i++) {
		if ((divid[0] % divid[i]) == 0) {
			if (divid[i] == divid[i - 1]) {
				max = divid[i];
				break;
			}
		}
		else {
			max = divid[i];
			break;
		}
	}
	printf("%d %d", divid[0], max);
	
	return 0;
}