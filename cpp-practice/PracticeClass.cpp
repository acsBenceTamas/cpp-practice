#include "PracticeClass.h"

int PracticeClass::PracticeMethod(int input) 
{
	lastInput = input;
	return input * 2;
}

int PracticeClass::GetLastInput()
{
	return lastInput;
}

