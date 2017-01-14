// ConsoleApplication49.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace ::std;

struct Node {
	int value;
	Node *prev;
	Node *next;
};



void addNode(int value, Node **head);
void printList(Node **head);
void insertNode(int value, int pos, Node **head);
void removeNode(int pos, Node **head);
int find(int value, Node **head);
int get(int pos, Node **head);

int main() {

	Node *head = NULL;

	addNode(1, &head);
	addNode(2, &head);
	addNode(3, &head);
	addNode(4, &head);
	addNode(5, &head);
	cout << get(2, &head)<<endl;
	cout << find(3, &head)<<endl;
	insertNode(9, 3, &head);
	removeNode(6, &head);

	printList(&head);


	_gettch();
	return 0;
}

void addNode(int value, Node **head) {
	Node *newNode = new Node();
	newNode->value = value;
	if (*head == NULL) {
		*head = newNode;
		newNode->prev = NULL;
		newNode->next = NULL;
		return;
	}
	Node *tmpHead = *head;
	while (tmpHead->next) {
		tmpHead = tmpHead->next;
	}
	tmpHead->next = newNode;
	newNode->prev = tmpHead;
	newNode->next = NULL;
}

void printList(Node **head) {
	Node *tmpHead = *head;
	while (tmpHead) {
		std::cout << tmpHead->value;
		tmpHead = tmpHead->next;
	}
}

void insertNode(int value, int pos, Node **head) {

	if (*head == NULL) {
		addNode(value, head);
		return;
	}

	Node *newNode = new Node();
	newNode->value = value;

	if (pos == 1 && *head) {
		newNode->next = *head;
		(*head)->prev = newNode;
		newNode->prev = NULL;
		*head = newNode;
		return;
	}


	Node *tmpHead = *head;
	int i = 1;
	for (i = 2; i < pos && tmpHead != NULL; i++) {
		tmpHead = tmpHead->next;
	}

	if (tmpHead == NULL && i != pos - 1) {
		std::cerr << "invalid position";
		return;
	}

	newNode->next = tmpHead->next;
	tmpHead->next = newNode;
	newNode->prev = tmpHead;
	if (newNode->next) {
		newNode->next->prev = newNode;
	}
	return;
}

void removeNode(int pos, Node **head) {
	if (*head == NULL) {
		std::cout << "empty list";
		return;
	}
	if (pos == 1) {
		Node *tmpCurr = NULL;
		tmpCurr = *head;
		*head = tmpCurr->next;
		tmpCurr->next->prev = NULL;
		delete tmpCurr;
		return;
	}

	Node *tmpHead = *head;
	int i = 1;
	for (i = 2; i < pos && tmpHead != NULL; i++) {
		tmpHead = tmpHead->next;
	}

	if (tmpHead->next == NULL) {
		std::cerr << "invalid position";
		return;
	}

	Node *tmpCurr = NULL;
	tmpCurr = tmpHead->next;
	tmpHead->next = tmpCurr->next;
	if (tmpCurr->next) {
		tmpCurr->next->prev = tmpHead;
	}

	delete tmpCurr;
}

int find(int value, Node **head) {
	if (*head == NULL) {
		std::cout << "empty list";
		return -1;
	}
	Node *tmpHead = *head;
	int i = 1;
	while (tmpHead) {
		if (tmpHead->value == value) {
			return i;
		}
		tmpHead = tmpHead->next;
		i++;
	}
	std::cout << "no matching";
	return -1;
}

int get(int pos, Node **head) {

	if (*head == NULL) {
		std::cout << "empty list";
		return -1;
	}

	Node *tmpHead = *head;
	int i = 1;

	for (i = 1; i < pos && tmpHead != NULL; i++) {
		tmpHead = tmpHead->next;
	}
	if (tmpHead == NULL) {
		std::cerr << "invalid position";
		return -1;
	}
	return tmpHead->value;


}

