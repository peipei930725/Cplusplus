#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>

using namespace std;

struct student {
	string name;
	int id;
};

void func(student& account);

int main() {
	student John;
	func(John);
}

void func(student& account) {
	cin >> account.name;
	cout << "student1 name is " << account.name << "\n";
	cin >> account.id;
	//cout << "student1 name is "<< account.name << endl;
	cout << "student1 id is " << account.id << endl;
}