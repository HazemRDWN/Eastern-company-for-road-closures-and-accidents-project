#pragma once
#include <iostream>
#include "LinkedList.h"
using namespace std;

template <class T>
class Queue {
private:
	LinkedList<T> List;
public:
	Queue() {}
	bool IsEmpty() {
		if (List.GetSize() == 0) {
			return true;
		}
		return false;
	}
	bool Enqueue(T Data, int Priority = 0) {
		List.Insert(List.GetSize(), Data, Priority);
		return true;
	}
	bool InsertAt(int index, T Data, int Priority = 0) {
		List.Insert(index, Data, Priority);
		return true;
	}
	void Dequeue() {
		if (IsEmpty()) {
			cout << "Queue is Empty!" << endl;
			return;
		}
		List.Delete(0);
	}
	T Front() {
		if (IsEmpty()) {
			cout << "Queue is Empty!" << endl;
			return T();
		}
		Node<T>* frontNode = List.GetNodeAt(0);
		if (frontNode == nullptr) {
			cout << "Front node is not available!" << endl;
			return T();
		}
		return frontNode->GetValue();
	}
	int Size() {
		return List.GetSize();
	}
	int AtVal(int In) {
		if (In < 0 || In >= List.GetSize()) {
			cout << "Index out of bounds!" << endl;
			return -1;
		}
		Node<T>* nodeAt = List.GetNodeAt(In);
		if (nodeAt == nullptr) {
			cout << "Node at index " << In << " is not available!" << endl;
			return -1;
		}
		return nodeAt->GetValue();
	}
	int AtPri(int In) {
		if (In < 0 || In >= List.GetSize()) {
			cout << "Index out of bounds!" << endl;
			return -1;
		}
		Node<T>* nodeAt = List.GetNodeAt(In);
		if (nodeAt == nullptr) {
			cout << "Node at index " << In << " is not available!" << endl;
			return -1;
		}
		return nodeAt->GetPriority();
	}
	bool RemoveByID(T Val) {
		List.DeleteByValue(Val);
		return true;
	}
};