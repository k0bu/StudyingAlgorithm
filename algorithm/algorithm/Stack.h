#pragma once
class Stack
{
private:
	int top;
	int maxSize;
	int* stackArray;
public:
	Stack(int size);
	void Initialize(int size);
	void Push(int x);
	int Pop();
	bool IsEmpty();
	bool IsFull();
	~Stack();
};

