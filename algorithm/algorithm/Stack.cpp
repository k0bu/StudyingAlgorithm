#include "pch.h"
#include "Stack.h"
#include <iostream>

Stack::Stack(int size)
{
	Initialize(size);
}

void Stack::Initialize(int size) {
	top = 0;
	maxSize = size;
	stackArray = new int[size];
}

void Stack::Push(int x) {
	if (IsFull()) {
		std::cout << "Stack is Full.\n";
		return;
	}
	stackArray[++top] = x;
}

int Stack::Pop() {
	if (IsEmpty()) {
		std::cout << "Stack is Empty.\n";
		return -9999999;
	}
	top--;
	return stackArray[top + 1];
}

bool Stack::IsEmpty() {
	return !(top > 0);
}

bool Stack::IsFull() {
	return !(top < maxSize);
}

Stack::~Stack()
{
	delete[] stackArray;
}
