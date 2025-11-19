#pragma once
#include "Queue.h"

template <class T>
class PriorityQueue {
private:
	Queue<T> Q;
public:
	PriorityQueue() {}
	bool IsEmpty() {
		return Q.IsEmpty();
	}
	bool Traversal() {
		for (int i = 0; i < Q.Size(); i++) {
			cout << Q.AtVal(i);
			cout << Q.AtPri(i);
		}
		return true;
	}
	bool Enqueue(T Data, int Priority) {
		if (Q.IsEmpty()) {
			Q.Enqueue(Data, Priority);
			return true;
		}
		int insertIndex = 0;
		while (insertIndex < Q.Size() && Q.AtPri(insertIndex) >= Priority) {
			insertIndex++;
		}
		Q.InsertAt(insertIndex, Data, Priority);
		return true;
	}
	bool Dequeue() {
		Q.Dequeue();
		return true;
	}
	T Front() {
		return Q.Front();
	}
	int Size() {
		return Q.Size();
	}
};