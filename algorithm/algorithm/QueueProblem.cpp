#include "pch.h"
#include "Queue.h"
#include <iostream>

#define LEN 100005
#define NAME_LEN 100

using namespace std;

struct ProcessCard {
	char name[NAME_LEN];
	int time;
};

void QueueProblem() {

	int elapsedTime = 0;
	int maxProcessNumber, quantum;
	Queue<ProcessCard> queue = Queue<ProcessCard>(LEN);
	ProcessCard process;

	scanf_s("%d %d", &maxProcessNumber, &quantum);

	for (int i = 0; i < maxProcessNumber; i++) {
		scanf_s("%s", process.name, NAME_LEN);
		scanf_s("%d", &process.time);
		queue.Enqueue(process);
	}

	while (!(queue.IsEmpty())) {
		process = queue.Dequeue();


		elapsedTime += (process.time > quantum) ? quantum : process.time;
		process.time = (process.time > quantum) ? process.time - quantum : 0;

		if (process.time > 0) {
			queue.Enqueue(process);
		}
		else {
			printf("%s %d\n", process.name, elapsedTime);
		}
	}

	
	
	return;
}
