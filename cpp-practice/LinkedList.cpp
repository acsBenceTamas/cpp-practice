#include "LinkedList.h"
#include "LinkedList.h"
#include "LinkedList.h"
#include "LinkedList.h"
#include "LinkedList.h"
#include <exception>

LinkedList::LinkedList()
{
	length = 0;
	currentNode = NULL;
	lastNode = NULL;
	firstNode = NULL;
}

LinkedList::~LinkedList()
{
	this->Clear();
}

int LinkedList::GetLength()
{
	return length;
}

int LinkedList::Get(int index)
{
	if (index < 0 || index >= length) { throw OutOfRangeException(); }
	return GetNode(index)->value;
}

int LinkedList::GetFirst()
{
	if (length == 0) {
		throw ListIsEmptyException();
	}
	return firstNode->value;
}

int LinkedList::GetLast()
{
	if (length == 0) {
		throw ListIsEmptyException();
	}
	return lastNode->value;
}

void LinkedList::Clear()
{
	while (length > 0) 
	{
		RemoveFirst();
	}
}

void LinkedList::Add(int value)
{
	LinkedList::AddToEnd(value);
}

void LinkedList::AddToEnd(int value)
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

void LinkedList::AddToStart(int value)
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

void LinkedList::Insert(int value, int index)
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

void LinkedList::RemoveFirst()
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

void LinkedList::RemoveLast()
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

void LinkedList::Remove(int index)
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

LinkedList::Node* LinkedList::GetNode(int index)
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
