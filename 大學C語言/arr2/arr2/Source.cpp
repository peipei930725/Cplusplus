#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define pi 3.14159

using namespace std;

/*string str(string bombom) {
	bombom[1] = 's';
	return bombom;
}*/

void square(int num) {
	int v2, *p2;
	v2 = 44;
	cout << &v2 << endl;
}

int main() {
	//string bombom1;
	int arr[5] = { 5,4,8,9,7 };
	int v1, *p1;
	int* p2;
	p2 = arr;
	p1 = new int;
	//p2 += 4;
	cout << *p2 << endl;
	cout << &arr[0] << endl;
	cout << &arr[1] << endl;
	cout << &arr[2] << endl;
	cout << &arr[3] << endl;
	cout << &arr[4] << endl;

	//scanf_s("%s", &bombom1);
	//cout << a[1];
	//printf("%b\n", a[1]);

	system("pause");
	return 0;
}