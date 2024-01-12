#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct node {
	int data;
	node* next;
};
void traversal(node* head) {//尋訪
	if (head == NULL) {
		printf("list為空!\n");
		return;
	}
	node* now = head;

	printf("list內有: ");
	while (head != NULL) {//一位一位輸出
		printf("%d->", now->data);
		now = now->next;
	}
	printf("\n\n");
}
bool push_back(int num,node *head) {//在最後新增一個num
	node* new_one = new node;//新的最後一位

	new_one->data = num;//指定要新增的值
	new_one->next = NULL;//將他的next設為null

	node* last = head;

	while (last->next != NULL) {//找到原來的list的最後一位
		last = last->next;
	}
	last->next = new_one;//接上list
}
bool insert(int pos, int val) {

}
int main() {
	node* n1 = new node;
	node* n2 = new node;
	node* n3 = new node;

	node* head = n1;

	n1->data = 10;
	n1->next = n2;

	n2->data = 20;
	n2->next = n3;

	n3->data = 30;
	n3->next = NULL;

	int input = 0;
	while (scanf("%d", &input) != EOF) {
		if (input == 1) {
			traversal(head);
		}
	}

}