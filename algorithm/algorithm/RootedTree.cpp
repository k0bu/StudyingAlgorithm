#include "pch.h"
#include <iostream>
#include <stdio.h>

using namespace std;

#define MAX 100005
#define NIL -1

struct Node {
	int parent, childLeft, childAdjacent;
};

Node *rootedTreeArray;
int *depthArray;

void PrintNodeInformation (int id) {
	printf ("node %d: ", id);
	printf ("parent = %d, ", rootedTreeArray[id].parent);
	printf ("depth = %d, ", depthArray[id]);
}

void PrintNodeType (Node node) {
	if (node.parent == NIL) {
		printf ("root, ");
	}
	else if (node.childLeft == NIL) {
		printf ("leaf, ");
	}
	else {
		printf ("internal node, ");
	}
}

void PrintChildNodes (int id) {
	printf ("[");

	for (int i = 0, c = rootedTreeArray[id].childLeft; c != NIL; i++, c = rootedTreeArray[c].childAdjacent) {
		if (i) printf (", ");
		printf ("%d", c);
	}

	printf ("]\n");
}

void Print (int id) {
	PrintNodeInformation(id);

	PrintNodeType(rootedTreeArray[id]);

	PrintChildNodes(id);

}

void Recursive (int id, int parentDepth) {
	depthArray[id] = parentDepth;
	if (rootedTreeArray[id].childAdjacent != NIL) {
		Recursive(rootedTreeArray[id].childAdjacent, parentDepth);
	}
	if (rootedTreeArray[id].childLeft != NIL) {
		Recursive(rootedTreeArray[id].childLeft, parentDepth + 1);
	}
}

void Initializing (int n) {
	rootedTreeArray = new Node[n];
	depthArray = new int[n];

	for (int i = 0; i < n; i++) {
		rootedTreeArray[i].parent = rootedTreeArray[i].childLeft = rootedTreeArray[i].childAdjacent = NIL;
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
				rootedTreeArray[id].childLeft = child;
			}
			else {
				rootedTreeArray[left].childAdjacent = child;
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