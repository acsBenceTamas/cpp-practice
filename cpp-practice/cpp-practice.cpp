// cpp-practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PracticeClass.h"

using namespace std;

int main()
{
    cout << "Input a number:\n";
	PracticeClass pc;
	cin >> pc.integer;
	cout << "The double of " << pc.integer << " is " << pc.PracticeMethod(pc.integer) << endl;
	cout << "Input the same number again please!\n";
	while (true)
	{
		cin >> pc.integer;
		if (pc.integer == pc.GetLastInput())
		{
			cout << "You input the proper integer of " << pc.GetLastInput() << endl;
			break;
		}
		else
		{
			cout << "You input " << pc.integer << " instead of " << pc.GetLastInput() << endl;
			cout << "Please try again!" << endl;
		}
	}
	cout << "Press any key to exit!" << endl;
	cin.get();
	cout << "This happens after pressing enter";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
