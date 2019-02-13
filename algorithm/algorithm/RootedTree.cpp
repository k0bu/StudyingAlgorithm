#include "pch.h"
#include <iostream>
#include <stdio.h>

using namespace std;

#define MAX 100005
#define NIL -1

struct Node {
	int parent, left, right;
};

Node *rootedTreeArray;
int *depthArray;

void Print (int id) {
	printf("node %d: ",id);
	printf ("parent = %d, ", rootedTreeArray[id].parent);
	printf("depth = %d, ", depthArray[id]);

	if (rootedTreeArray[id].parent == NIL) {
		printf("root, ");
	}
	else if (rootedTreeArray[id].left == NIL) {
		printf("leaf, ");
	}
	else {
		printf("internal node, ");
	}

	printf("[");

	for (int i = 0, c = rootedTreeArray[id].left; c != NIL; i++, c = rootedTreeArray[c].right) {
		if(i) printf(", ");
		printf("%d", c);
	}

	printf("]\n");

}

void Recursive (int id, int parentDepth) {
	depthArray[id] = parentDepth;
	if (rootedTreeArray[id].right != NIL) {
		Recursive(rootedTreeArray[id].right, parentDepth);
	}
	if (rootedTreeArray[id].left != NIL) {
		Recursive(rootedTreeArray[id].left, parentDepth + 1);
	}
}

void Initializing (int n) {
	rootedTreeArray = new Node[n];
	depthArray = new int[n];

	for (int i = 0; i < n; i++) {
		rootedTreeArray[i].parent = rootedTreeArray[i].left = rootedTreeArray[i].right = NIL;
	}
}

void Scanning (int n) {
	int id, number, left;
	for (int i = 0; i < n; i++) {
		scanf_s("%d %d", &id, &number);

		for (int j = 0; j < number; j++) {
			int child;
			scanf_s("%d", &child);

			if (j == 0) {
				rootedTreeArray[id].left = child;
			}
			else {
				rootedTreeArray[left].right = child;
			}

			left = child;
			rootedTreeArray[child].parent = id;
		}

	}
}

void RootedTree () {
	int n, root;

	scanf_s("%d", &n);

	Initializing(n);

	Scanning(n);

	for (int i = 0; i < n; i++) {
		if (rootedTreeArray[i].parent == NIL) {
			root = i;
		}
	}

	Recursive(root , 0);

	for (int i = 0; i < n; i++) {
		Print(i);
	}


	return;
}