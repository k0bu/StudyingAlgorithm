#include "pch.h"
#include "Queue.h"
#include <iostream>

//using namespace std;
//
//
//template <typename T>
//Queue<T>::Queue(int queueSize)
//{
//	Initialize(queueSize);
//}
//
//template <typename T>
//void Queue<T>::Initialize(int queueSize) {
//	head = tail = 0;
//	queueSize = queueSize;
//	queueArray = new T[queueSize];
//}
//
//template <typename T>
//void Queue<T>::Enqueue(T x) {
//	if (IsFull()) {
//		cout << "Queue is Full\n";
//		return;
//	}
//	queueArray[tail] = x;
//	tail = (++tail == queueSize) ? 0 : tail;
//}
//
//template <typename T>
//T Queue<T>::Dequeue() {
//	if (IsEmpty()) {
//		cout << "Queue is Empty\n";
//		return -9999999;
//	}
//	T dequeuingValue = queueArray[head];
//	delete queueArray[head];
//	head = (++head == queueSize) ? 0 : head;
//	
//	return dequeuingValue;
//
//}
//
//template <typename T>
//bool Queue<T>::IsFull() {
//	return head == (tail + 1) % queueSize;
//}
//
//template <typename T>
//bool Queue<T>::IsEmpty() {
//	return head == tail;
//}
//
//template <typename T>
//Queue<T>::~Queue()
//{
//}
