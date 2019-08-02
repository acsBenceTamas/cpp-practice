#pragma once
#include <exception>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	int GetLength();
	int Get(int index);
	int GetFirst();
	int GetLast();
	void Clear();
	void Add(int value);
	void AddToStart(int value);
	void AddToEnd(int value);
	void Insert(int value, int index);
	void RemoveFirst();
	void RemoveLast();
	void Remove(int index);
	struct OutOfRangeException : public std::exception {
		const char* what() const throw () {
			return "Index is out of range.";
		}
	};
	struct ListIsEmptyException : public std::exception {
		const char* what() const throw () {
			return "List is empty.";
		}
	};
private:
	struct Node
	{
		int value;
		Node* next;
		Node* previous;
	};
	int length;
	Node* firstNode;
	Node* lastNode;
	Node* currentNode;
	Node* GetNode(int index);
};