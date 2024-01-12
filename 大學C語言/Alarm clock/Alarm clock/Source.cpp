#include<iostream>
#include<string>

using namespace std;

int main() {
	int casenum = 0;
	int arr[31] = {0};
	int count[31] = { 0 };
	int casecount = 1;
	int output = 0;
	int totalcount = 1;
	bool trueorflase = false;
	while (cin >> casenum) {
		if (casenum > 10000)
			return 0;
		output = 0;
		casecount = 1;
		while (casecount < casenum + 1) {
			trueorflase = false;
			int arr[30] = { 0 };
			int count[30] = { 0 };
			string name;
			cin >> name;
			if (name.length() == 1) {
				casecount++;
				continue;
			}
			for (int i = 0; i < name.length(); ++i) {
				arr[name[i] - 'a']++;
			}
			for (int i = 0; i < 26; ++i) {
				count[arr[i]]++;
			}
			for (int i = 1; i < 30; ++i) {
				if (count[i] > 1) {
					trueorflase =true;
					break;
				}
			}
			if (!trueorflase)
				output++;
			casecount++;
		}
		cout << "Case " << totalcount << ": " << output << endl;
		totalcount++;
	}
	return 0;
}