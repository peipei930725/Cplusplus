#include<iostream>
#include<string>

using namespace std;

int main() {
	int testcases = 0;
	while (cin >> testcases) {
		for (int i = 0; i < testcases; ++i) {
			int trainline = 0, count = 0;;
			cin >> trainline;
			int arr[50] = { 0 };
			for (int j = 0; j < trainline; ++j) {
				cin >> arr[j];
			}
			for (int m = 0; m < trainline; ++m) {
				for (int n = 1; 0 < trainline-m-n; ++n) {
					if (arr[n-1] > arr[n]) {
						int temp = arr[n-1];
						arr[n-1] = arr[n];
						arr[n ] = temp;
						count++;
					}
				}
			}
			cout << "Optimal train swapping takes "<<count<<" swaps." << endl;
		}
	}
	return 0;
}