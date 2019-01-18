#include "pch.h"
#include <iostream>
#include "stdio.h"
#include "DoublyLinkedList.h"

using namespace std;


void DoublyLinkedListProblem() {
	int key, n;
	char command[20];

	scanf_s("%d", &n);

	DoublyLinkedList list = DoublyLinkedList();

	for (int i = 0; i < n; i++) {
		scanf_s("%s %d", command, 20, &key);
		if (command[0] == 'i') {
			list.Insert(key);
		}
		else if (command[0] == 'd') {
			if (strlen(command) > 6) {
				if (command[6] == 'F') list.DeleteFirst();
				if (command[6] == 'L') list.DeleteLast();
			}
			else {
				list.DeleteKey(key);
			}
		}
		
	}

	list.PrintList();

	return;
}