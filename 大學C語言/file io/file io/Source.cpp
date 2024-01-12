#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct student {
	char name[20];
	int height;
	int weight;
};

int main() {
	FILE* fptr =fopen("text.txt", "r+");
	student one = { "wesley",175,60 };

	if (fptr == NULL) {
		printf("fail to	open file\n");
		return 0;
	}
	fprintf(fptr, "%s\n", one.name);
	fprintf(fptr, "%d\n", one.height);
	fprintf(fptr, "%d\n", one.weight);

	fclose(fptr);
}