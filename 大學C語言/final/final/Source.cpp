#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct node {
	int data;
	node* next;
};
void traversal(node* head) {//�M�X
	if (head == NULL) {
		printf("list����!\n");
		return;
	}
	node* now = head;

	printf("list����: ");
	while (head != NULL) {//�@��@���X
		printf("%d->", now->data);
		now = now->next;
	}
	printf("\n\n");
}
bool push_back(int num,node *head) {//�b�̫�s�W�@��num
	node* new_one = new node;//�s���̫�@��

	new_one->data = num;//���w�n�s�W����
	new_one->next = NULL;//�N�L��next�]��null

	node* last = head;

	while (last->next != NULL) {//����Ӫ�list���̫�@��
		last = last->next;
	}
	last->next = new_one;//���Wlist
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