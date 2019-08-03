#pragma once
#include "ListIsNotEmptyException.h"
#include "OutOfRangeException.h"

template <typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	int GetLength();
	T Get(int index);
	T GetFirst();
	T GetLast();
	void Clear();
	void Add(T value);
	void AddToStart(T value);
	void AddToEnd(T value);
	void Insert(T value, int index);
	void RemoveFirst();
	void RemoveLast();
	void Remove(int index);
private:
	template <typename T>
	struct Node
	{
		T value;
		Node<T>* next;
		Node<T>* previous;
	};
	int length;
	Node<T>* firstNode;
	Node<T>* lastNode;
	Node<T>* currentNode;
	Node<T>* GetNode(int index);
};

template<typename T>
LinkedList<T>::LinkedList()
{
	length = 0;
	currentNode = NULL;
	lastNode = NULL;
	firstNode = NULL;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	this->Clear();
}

template<typename T>
int LinkedList<T>::GetLength()
{
	return length;
}

template<typename T>
T LinkedList<T>::Get(int index)
{
	if (index < 0 || index >= length) { throw OutOfRangeException(); }
	return GetNode(index)->value;
}

template<typename T>
T LinkedList<T>::GetFirst()
{
	if (length == 0) {
		throw ListIsEmptyException();
	}
	return firstNode->value;
}

template<typename T>
T LinkedList<T>::GetLast()
{
	if (length == 0) {
		throw ListIsEmptyException();
	}
	return lastNode->value;
}

template<typename T>
void LinkedList<T>::Clear()
{
	while (length > 0)
	{
		RemoveFirst();
	}
}

template<typename T>
void LinkedList<T>::Add(T value)
{
	LinkedList::AddToEnd(value);
}

template<typename T>
void LinkedList<T>::AddToEnd(T value)
{
	if (length == 0)
	{
		firstNode = new Node<T>;
		lastNode = firstNode;
	}
	else
	{
		currentNode = lastNode;
		currentNode->next = new Node<T>;
		lastNode = currentNode->next;
		lastNode->previous = currentNode;
	}
	lastNode->value = value;
	length++;
}

template<typename T>
void LinkedList<T>::AddToStart(T value)
{
	if (length == 0)
	{
		firstNode = new Node<T>;
		lastNode = firstNode;
	}
	else
	{
		currentNode = firstNode;
		currentNode->previous = new Node<T>;
		firstNode = currentNode->previous;
		firstNode->next = currentNode;
	}
	firstNode->value = value;
	length++;
}

template<typename T>
void LinkedList<T>::Insert(T value, int index)
{
	if (index == length)
	{
		AddToEnd(value);
		return;
	}
	if (index == 0)
	{
		AddToStart(value);
		return;
	}
	if (index < 0 || index > length) { throw OutOfRangeException(); }
	currentNode = GetNode(index);
	Node<T>* newNode = new Node<T>;
	newNode->value = value;
	newNode->previous = currentNode->previous;
	newNode->next = currentNode;
	currentNode->previous->next = newNode;
	currentNode->previous = newNode;
	length++;
}

template<typename T>
void LinkedList<T>::RemoveFirst()
{
	if (length == 0) {
		throw ListIsEmptyException();
	}
	currentNode = firstNode;
	if (currentNode->next)
	{
		firstNode = currentNode->next;
	}
	delete currentNode;
	length--;
}

template<typename T>
void LinkedList<T>::RemoveLast()
{
	if (length == 0) {
		throw ListIsEmptyException();
	}
	currentNode = lastNode;
	if (currentNode->previous)
	{
		lastNode = currentNode->previous;
	}
	delete currentNode;
	length--;
}

template<typename T>
void LinkedList<T>::Remove(int index)
{
	if (length == 0) {
		throw ListIsEmptyException();
	}
	if (index == 0)
	{
		RemoveFirst();
		return;
	}
	if (index == length - 1)
	{
		RemoveLast();
		return;
	}
	if (index < 0 || index >= length) { throw OutOfRangeException(); }
	currentNode->next->previous = currentNode->previous;
	currentNode->previous->next = currentNode->next;
	delete currentNode;
	length--;
}

template<typename T>
LinkedList<T>::Node<T>* LinkedList<T>::GetNode(int index)
{
	if (index == 0) { return firstNode; }
	else if (index == length - 1) { return lastNode; }
	currentNode = firstNode;
	for (size_t i = 0; i < index; i++)
	{
		currentNode = currentNode->next;
	}
	return currentNode;
}
