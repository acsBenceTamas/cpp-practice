#include "LinkedList.h"

LinkedList::LinkedList()
{
	length = 0;
	currentNode = 0;
	lastNode = 0;
	firstNode = 0;
}

LinkedList::~LinkedList()
{
	currentNode = firstNode;
	while (currentNode->next != nullptr)
	{
		firstNode = currentNode->next;
		delete currentNode;
	}
	delete currentNode;
	delete lastNode;
}

int LinkedList::GetFirst()
{
	return firstNode->value;
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

int LinkedList::GetLength()
{
	return length;
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
	lastNode->value = value;
	length++;
}