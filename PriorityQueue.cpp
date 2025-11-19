#include "PriorityQueue.h"

int main() {
	PriorityQueue<int> PQ;
	PQ.Enqueue(10, 1);
	PQ.Enqueue(20, 3);
	PQ.Enqueue(15, 2);
	cout << "front element: " << PQ.Front() << endl;
	cout << "size: " << PQ.Size() << endl;
	PQ.Dequeue();
	cout << "front element: " << PQ.Front() << endl;
	cout << "size: " << PQ.Size() << endl;
	return 0;
}