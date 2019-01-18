#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Queue
{
private:
	T* queueArray;
	int head;
	int tail;
	int queueSize;
public:
	Queue(int queueSize)
	{
		Initialize(queueSize);
	}
	void Initialize(int size) {
		head = tail = 0;
		queueSize = size;
		queueArray = new T[queueSize];
	}
	void Enqueue(T x) {
		if (IsFull()) {
			cout << "Queue is Full\n";
			return;
		}
		queueArray[tail] = x;
		tail = (++tail == queueSize) ? 0 : tail;
	}
	T Dequeue() {
		if (IsEmpty()) {
			cout << "Queue is Empty\n";
			//Write something that will throw error.
		}
		T dequeuingValue = queueArray[head];
		head = (++head == queueSize) ? 0 : head;

		return dequeuingValue;

	}
	bool IsFull() {
		return head == ((tail + 1) % queueSize);
	}
	bool IsEmpty() {
		return head == tail;
	}
	
	~Queue() {}
};

