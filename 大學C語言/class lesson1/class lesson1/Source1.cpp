#include<iostream>

using namespace std;

class student {
public:
	int grade;
	int b;
	string name;
private:
};

int main() {
	student John;
	John.grade = 99;
	John.name = "Jonny";
	cout << John.name << " grade is " << John.grade << endl;

	return 0;
}