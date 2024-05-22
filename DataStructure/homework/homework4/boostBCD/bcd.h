#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

class BCD64 {
    public:
	BCD64();

	BCD64(unsigned long long bcd);

	BCD64(const BCD64 &bcd_obj);

	BCD64(string &num_str);

	BCD64 add(BCD64 &num, int &carryout, int &carryin) ;

	BCD64 sub(BCD64 &num, int &carryout, int &carryin) ;
            
	friend ostream &operator<<(ostream &sout, BCD64 &num);

    //private:
	unsigned long long bcd;
};

ostream &operator<<(ostream &sout, BCD64 &num) {
	sout << num.bcd;
	return sout;
}

class ListNode {
public:
    BCD64 obj;
	ListNode *next;
	ListNode *reverseLinkedList(ListNode* head);

	ListNode(BCD64 obj) {
		this->obj = obj;
		next = nullptr;
	}
};

class stringtolink {//字串處理
public:
	ListNode* head;
	stringtolink(string num);	
	void link_add(ListNode* node);
	void link_sub(ListNode* node);
	void print();
};