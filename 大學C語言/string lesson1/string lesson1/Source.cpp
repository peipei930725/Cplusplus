#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

void func(int ** x) {
	**x = **x * **x;
}

int main() {
	int arr1[3][3] = { 0 };
	int arr2[3] = { 1,2,3 };
	int* ptr1, num=10;
	ptr1 = arr2;

	cout << *ptr1 << endl;

	return 0;
}