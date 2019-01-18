#pragma once
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Node {
	int key;
	Node *prev, *next;
};
class DoublyLinkedList
{
private:
	Node *sentinel;
public:
	DoublyLinkedList() {
		Initialize();
	}
	void Initialize() {
		sentinel = new Node;
		sentinel->prev = sentinel;
		sentinel->next = sentinel;
	}
	Node *ListSearch(int key) {
		Node *current = sentinel->next;
		while (current != sentinel && current->key != key) {
			current = current->next;
		}
		return current;
	}
	int ListSize() {
		int count = 0;
		Node *current = sentinel->next;
		while (current != sentinel) {
			count++;
			current = current->next;
		}
		return count;
	}
	void PrintList() {
		Node *current = sentinel->next;
		int iterator = 0;
		while (1) {
			if (current == sentinel) break;
			if (iterator++) printf(" ");
			printf("%d", current->key);
			current = current->next;
		}
		printf("\n");
	}
	void Insert(int key) {
		Node *x = new Node;
		x->key = key;
		x->next = sentinel->next;
		sentinel->next->prev = x;
		sentinel->next = x;
		x->prev = sentinel;
	}
	void DeleteNode(Node *node) {
		if (node == sentinel) return;
		node->next->prev = node->prev;
		node->prev->next = node->next;
		delete node;
	}
	void DeleteFirst() {
		DeleteNode(sentinel->next);
	}
	void DeleteLast() {
		DeleteNode(sentinel->prev);
	}
	void DeleteKey(int key) {
		DeleteNode(ListSearch(key));
	}
	void DeleteAll() {

	}
	~DoublyLinkedList() {

	}
};

