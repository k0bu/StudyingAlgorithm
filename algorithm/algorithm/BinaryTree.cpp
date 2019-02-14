#include "pch.h"
#include <iostream>
#include <stdio.h>

using namespace std;

#define MAX 1000
#define NIL -1

struct Node {
	int parent, left, right;
};

Node *binaryTreeArray;
int *depthBinaryArray, *heightBinaryArray;

void SetDepth (int id, int depth) {
	if (id == NIL) {
		return;
	}

	depthBinaryArray[id] = depth;

	SetDepth(binaryTreeArray[id].left , depth + 1);
	SetDepth (binaryTreeArray[id].right , depth + 1);
}

int SetHeight (int id) {
	int h1 = 0, h2 = 0;

	if (binaryTreeArray[id].left != NIL) {
		h1 = SetHeight(binaryTreeArray[id].left) + 1;
	}

	if (binaryTreeArray[id].right != NIL) {
		h2 = SetHeight (binaryTreeArray[id].right) + 1;
	}

	return heightBinaryArray[id] = (h1 > h2) ? h1 : h2;
}

int GetSiblings (int id) {
	if (binaryTreeArray[id].parent == NIL) {
		return NIL;
	}
	if (binaryTreeArray[binaryTreeArray[id].parent].left != id && binaryTreeArray[binaryTreeArray[id].parent].left != NIL) {
		return binaryTreeArray[binaryTreeArray[id].parent].left;
	}
	if (binaryTreeArray[binaryTreeArray[id].parent].right != id && binaryTreeArray[binaryTreeArray[id].parent].right != NIL) {
		return binaryTreeArray[binaryTreeArray[id].parent].right;
	}

	return NIL;
}

void ScanningBinaryTree (int n) {
	int id, left, right;
	for (int i = 0; i < n; i++) {
		scanf_s ("%d %d %d", &id, &left, &right);

		binaryTreeArray[id].left = left;
		binaryTreeArray[id].right = right;

		if (left != NIL) {
			binaryTreeArray[left].parent = id;
		}
		if (right != NIL) {
			binaryTreeArray[right].parent = id;
		}

	}
}

void PrintBinaryTree (int id) {
	printf ("node %d: ", id);
	printf ("parent = %d, ", binaryTreeArray[id].parent);
	printf ("sibling = %d, ", GetSiblings(id) );

	int branchNumber = 0;

	if (binaryTreeArray[id].left != NIL) {
		branchNumber++;
	}
	if (binaryTreeArray[id].right != NIL) {
		branchNumber++;
	}

	printf ("degree = %d, ", branchNumber);
	printf ("depth = %d, ", depthBinaryArray[id]);
	printf ("height = %d, ", heightBinaryArray[id]);

	if (binaryTreeArray[id].parent == NIL) {
		printf("root\n");
	}
	else if (binaryTreeArray[id].left == NIL && binaryTreeArray[id].right == NIL) {
		printf("leaf\n");
	}
	else {
		printf("internal node\n");
	}

}

void BinaryTree () {

	int n, root = 0;

	scanf_s("%d", &n);

	binaryTreeArray = new Node[n];
	depthBinaryArray = new int[n], heightBinaryArray = new int[n];

	for (int i = 0; i < n; i++) {
		binaryTreeArray[i].parent = NIL;
	}

	ScanningBinaryTree(n);

	for (int i = 0; i < n; i++) {
		if (binaryTreeArray[i].parent == NIL) {
			root = i;
		}
	}

	SetDepth(root, 0);
	SetHeight(root);

	for (int i = 0; i < n; i++) {
		PrintBinaryTree(i);
	}

	return;
}