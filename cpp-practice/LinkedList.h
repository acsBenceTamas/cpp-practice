#pragma once
class LinkedList
{
public:
	struct Node
	{
		int value;
		Node *next;
		Node *previous;
	};
	LinkedList();
	~LinkedList();
	int GetFirst();
	int GetLength();
	void Add(int value);
	void AddToStart(int value);
	void AddToEnd(int value);
private:
	int length;
	Node *firstNode;
	Node *lastNode;
	Node *currentNode;
};