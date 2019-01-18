#include "pch.h"
#include <iostream>
#include "Stack.h"
#include <string>
#include <cstdlib>


#define BUF_SIZE 1024

using namespace std;

void StackProblem() {
	int a, b, N = 1000;
	char inputString[BUF_SIZE];


	Stack stack = Stack(N);

	while (scanf_s("%s", inputString, BUF_SIZE) != EOF) {
		if (*inputString == '+') {
			stack.Push( stack.Pop() + stack.Pop() );
		}
		else if (*inputString == '-') {
			b = stack.Pop();
			a = stack.Pop();
			stack.Push(a - b);
		}
		else if (*inputString == '*') {
			stack.Push(stack.Pop() * stack.Pop());
		}
		else {
			int number = atoi(inputString);
			stack.Push( number );
		}
		if (getchar() == '\n') {
			break;
		}
	}

	printf("%d\n", stack.Pop());

	return;
}
