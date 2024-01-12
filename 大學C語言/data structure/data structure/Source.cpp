#include<stdio.h>
#pragma warning(disable:4996)

struct node {
	int data;
	node* next;
};

node* head;

void traversal() {
	if (head == NULL) {
		printf("list現在為空!!!\n");
		return;
	}
	printf("list內有: ");
	while (head != NULL) {
		printf("%d->", head->data);
		head = head->next;
	}
	printf("\n\n");
}

int main() {
	node* n1 = new node();
	node* n2 = new node();
	node* n3 = new node();

	n1->data = 10;
	n1->next = n2;

	n2->data = 20;
	n2->next = n3;

	n3->data = 30;
	n3->next = NULL;

	head = n1;

	traversal();
}