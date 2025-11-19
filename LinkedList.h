#pragma once
#include <iostream>
using namespace std;
template <class T>

class Node {
private:
	T Value;
	Node* Next;
	int Priority;
public:
	Node(T Val, int Pri) { Value = Val; Next = nullptr; Priority = Pri; }
	T GetValue() { return Value; }
	void SetValue(T val) { Value = val; }
	Node* GetNext() { return Next; }
	void SetNext(Node* next) { Next = next; }
	int GetPriority() { return Priority; }
	//void SetPriority(int Pri) { Priority = Pri; }
};
template <class T>
class LinkedList {
private:
	Node<T>* Head;
	int ItemCount;
public:
	LinkedList() { Head = nullptr; ItemCount = 0; }
	Node<T>* GetNodeAt(int In) {
		if (In < 0 || In >= ItemCount) {
			return nullptr;
		}
		Node<T>* Temp = Head;
		for (int i = 0; i < In; i++) {
			Temp = Temp->GetNext();
		}
		return Temp;
	}
	int GetSize() {
		return ItemCount;
	}
	int print(LinkedList<T>* p) {
		Node<T>* temp = p->Head;
		while (temp != nullptr) {
			cout << temp->GetValue() << " ";
			temp = temp->GetNext();
		}
		return 0;
	}
	bool Insertbeg(T Data, int Priority = 0) {
		Node<T>* valptr = new Node<T>(Data, Priority);
		valptr->SetNext(Head);
		Head = valptr;
		ItemCount++;
		return true;
	}

	bool Insert(int In, T Data, int Priority = 0) {
		if (In == 0) {
			return Insertbeg(Data, Priority);
		}
		Node<T>* NodeAt = GetNodeAt(In);
		Node<T>* prev = GetNodeAt(In - 1);
		Node<T>* NewNode = new Node<T>(Data, Priority);
		if (In == ItemCount) {
			if (Head == nullptr) {
				Head = NewNode;
			}
			else {
				prev->SetNext(NewNode);
			}
			ItemCount++;
			return true;
		}
		if (NodeAt != nullptr) {
			NewNode->SetNext(NodeAt);
			prev->SetNext(NewNode);
			ItemCount++;
			return true;
		}
		return false;
	}

	bool Delete(int In) {
		if (In < 0 || In >= ItemCount) {
			return false;
		}
		if (In == 0) {
			Node<T>* temp = Head;
			Head = Head->GetNext();
			delete temp;
			ItemCount--;
			return true;
		}
		Node<T>* prev = GetNodeAt(In - 1);
		Node<T>* toDelete = prev->GetNext();
		prev->SetNext(toDelete->GetNext());
		delete toDelete;
		ItemCount--;
		return true;
	}
	bool DeleteByValue(T targetVal) {
		if (Head == nullptr) return false;

		if (Head->GetValue() == targetVal) {
			Delete(0);
			return true;
		}

		Node<T>* current = Head;
		while (current->GetNext() != nullptr) {
			if (current->GetNext()->GetValue() == targetVal) {
				Node<T>* temp = current->GetNext();
				current->SetNext(temp->GetNext());
				delete temp;
				ItemCount--;
				return true;
			}
			current = current->GetNext();
		}
		return false;
	}
	~LinkedList() {
		while (ItemCount > 0) {
			Delete(0);
		}
	}
};