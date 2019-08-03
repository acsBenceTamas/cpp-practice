#include <iostream>
#include "PracticeClass.h"
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList<int>* ll = new LinkedList<int>();
	cout << "Please input three integers!\n";
	while (ll->GetLength() < 3)
	{
		int i;
		cin >> i;
		if (cin.fail())
		{
			cout << "Please input a valid integer!\n";
			cin.clear();
			cin.ignore();
		}
		else 
		{
			ll->Add(i);
		}
	}
	cout << "Your integers were the following: \n";
	LinkedList<int> lil = *ll;
	for (LinkedList<int>::ForwardIterator iterator = lil.begin();
		iterator != lil.end(); iterator++) {
		cout << *iterator << " ";
	}
}
