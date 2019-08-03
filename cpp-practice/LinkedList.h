#pragma once
#include "ListIsNotEmptyException.h"
#include "OutOfRangeException.h"
#include "ItemNotFoundException.h"
#include <iterator>

using namespace std;

template <typename T>
class LinkedList
{
	struct Node;
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
	bool Contains(T value);
	int Find(T value);
	void RemoveFirst();
	void RemoveLast();
	void Remove(int index);

	class ForwardIterator;

	ForwardIterator begin()
	{
		return ForwardIterator(firstNode);
	}

	ForwardIterator end()
	{
		return ForwardIterator(nullptr);
	}

	class ForwardIterator : public iterator<forward_iterator_tag, T>
	{
		typedef ForwardIterator	iterator;
		const Node* currentPos;
	public:
		ForwardIterator()
		{
			this->currentPos = nullptr;
		}
		ForwardIterator(const Node* node)
		{
			this->currentPos = node;
		}

		ForwardIterator& operator++()
		{
			if (currentPos) currentPos = currentPos->next;
			return *this;
		}
		ForwardIterator operator++(int)
		{
			ForwardIterator iterator = *this;
			++* this;
			return iterator;
		}
		bool operator!=(const ForwardIterator iterator)
		{
			return currentPos != iterator.currentPos;
		}
		T operator*()
		{
			return currentPos->value;
		}
	};
private:
	struct Node
	{
		T value;
		Node* next = nullptr;
		Node* previous = nullptr;
		friend class ForwardIterator;
	};
	int length;
	Node* firstNode;
	Node* lastNode;
	Node* currentNode;
	Node* GetNode(int index)
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
};

template<typename T>
LinkedList<T>::LinkedList()
{
	length = 0;
	currentNode = nullptr;
	lastNode = nullptr;
	firstNode = nullptr;
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
		firstNode = new Node;
		lastNode = firstNode;
	}
	else
	{
		currentNode = lastNode;
		currentNode->next = new Node;
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
		firstNode = new Node;
		lastNode = firstNode;
	}
	else
	{
		currentNode = firstNode;
		currentNode->previous = new Node;
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
	Node* newNode = new Node;
	newNode->value = value;
	newNode->previous = currentNode->previous;
	newNode->next = currentNode;
	currentNode->previous->next = newNode;
	currentNode->previous = newNode;
	length++;
}

template<typename T>
inline bool LinkedList<T>::Contains(T value)
{
	currentNode = firstNode;
	while (currentNode)
	{
		if (currentNode->value == value)
		{
			return true;
		}
		currentNode = currentNode->next;
	}
	return false;
}

template<typename T>
inline int LinkedList<T>::Find(T value)
{
	bool found = false;
	int index = 0;
	currentNode = firstNode;
	while (currentNode) 
	{
		if (currentNode->value == value) 
		{
			found = true;
			break;
		}
		currentNode = currentNode->next;
		index++;
	}
	if (found)
	{
		return index;
	}
	throw ItemNotFoundException();
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